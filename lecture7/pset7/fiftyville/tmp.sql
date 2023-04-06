SELECT DISTINCT(people.name), people.phone_number FROM people 
JOIN bakery_security_logs 
ON people.license_plate = bakery_security_logs.license_plate 
AND people.license_plate IN (
    SELECT bakery_security_logs.license_plate 
    FROM bakery_security_logs 
    WHERE day = 28
    AND month = 7
    AND year = 2021
    AND hour = 10
    AND minute BETWEEN 19 AND 40
)
JOIN passengers 
ON people.passport_number = passengers.passport_number
AND people.passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id = 36
)
JOIN phone_calls 
ON people.phone_number = phone_calls.caller
AND people.phone_number IN (
    SELECT caller FROM phone_calls
    WHERE day = 28
    AND month = 7
    AND year = 2021
    AND duration < 60
)
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions 
ON bank_accounts.account_number = atm_transactions.account_number
AND people.id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE day = 28
        AND month = 7
        AND year = 2021
        AND atm_location = "Leggett Street"
        AND transaction_type = "withdraw"
    )
)
;
