SELECT people.name, people.id FROM people 
JOIN bank_accounts 
ON bank_accounts.person_id = people.id
JOIN atm_transactions 
ON bank_accounts.account_number = atm_transactions.account_number
WHERE people.license_plate IN (
    SELECT people.license_plate 
    FROM bakery_security_logs 
    WHERE day = 28 
    AND month = 7 
    AND hour = 10 
    AND minute BETWEEN 25 AND 35
    AND activity = "exit"
)
AND people.phone_number IN (
    SELECT caller 
    FROM phone_calls 
    WHERE day = 28 
    AND month = 7 
    AND year = 2021
)
AND people.passport_number IN (
    SELECT passport_number 
    FROM passengers
    WHERE flight_id = (
        SELECT id FROM flights
        WHERE id = 36
    )
)

AND people.id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE day = 28 
        AND year = 2021 
        AND month = 7 
        AND atm_location = "Leggett Street"
        AND transaction_type = "withdraw"
    )
) 
;
