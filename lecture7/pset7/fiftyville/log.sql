-- Keep a log of any SQL queries you execute as you solve the mystery.

-- to get the crime id:
SELECT id FROM crime_scene_reports WHERE street LIKE "Humphrey Street" AND day = 28 AND description LIKE "%CS50%";                                                                   
-- the id is 295;


-- to get crime description
SELECT description FROM crime_scene_reports WHERE street LIKE "Humphrey Street" AND day = 28 AND description LIKE "%CS50%";                                                                   
-- Theft the CS50 duck took place at 10:15am at the Humphrey Street bakery. 
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.


-- to get interviews and id
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE "%bakery%";
-- the ids are 161, 162, 163
-- 161 = Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame. 
-- 162 = I dont know the thiefs name, but it was someone I recognized. Earlier this morning, before I arrived at Emmas bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163 = As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- to get license_plates of bakery_security_logs
SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute BETWEEN 20 AND 40;

-- to get account_number of all withdraw atm_transactions 
SELECT account_number FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

-- to get the the first flight of next day
SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8;

-- to get the phone_calls of day
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021;

-- to get the name of airport escape destination
SELECT * FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8);

-- Cross-referencing all the data to find the criminal.

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
    AND minute BETWEEN 15 AND 30
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

-- to find the accomplice

SELECT DISTINCT(name), phone_number FROM people 
JOIN phone_calls 
ON people.phone_number = phone_calls.caller
AND people.phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE day = 28
    AND month = 7
    AND year = 2021
    AND duration < 60
    AND caller = "(367) 555-5533" 
)
;
