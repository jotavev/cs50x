-- Keep a log of any SQL queries you execute as you solve the mystery.

-- to get the crime id:
-- SELECT id FROM crime_scene_reports WHERE street LIKE "Humphrey Street" AND day = 28 AND description LIKE "%CS50%";                                                                   
-- the id is 295;


-- to get crime description
-- SELECT description FROM crime_scene_reports WHERE street LIKE "Humphrey Street" AND day = 28 AND description LIKE "%CS50%";                                                                   
-- Theft the CS50 duck took place at 10:15am at the Humphrey Street bakery. 
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.


-- to get interviews and id
-- SELECT * FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE "%bakery%";
-- the ids are 161, 162, 163
-- 161 = Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame. 
-- 162 = I dont know the thiefs name, but it was someone I recognized. Earlier this morning, before I arrived at Emmas bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163 = As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.



SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute BETWEEN 15 AND 40;
┌─────┬──────┬───────┬─────┬──────┬────────┬──────────┬───────────────┐
│ id  │ year │ month │ day │ hour │ minute │ activity │ license_plate │
├─────┼──────┼───────┼─────┼──────┼────────┼──────────┼───────────────┤
│ 260 │ 2021 │ 7     │ 28  │ 10   │ 16     │ exit     │ 5P2BI95       │
│ 261 │ 2021 │ 7     │ 28  │ 10   │ 18     │ exit     │ 94KL13X       │
│ 262 │ 2021 │ 7     │ 28  │ 10   │ 18     │ exit     │ 6P58WS2       │
│ 263 │ 2021 │ 7     │ 28  │ 10   │ 19     │ exit     │ 4328GD8       │
│ 264 │ 2021 │ 7     │ 28  │ 10   │ 20     │ exit     │ G412CB7       │
│ 265 │ 2021 │ 7     │ 28  │ 10   │ 21     │ exit     │ L93JTIZ       │
│ 266 │ 2021 │ 7     │ 28  │ 10   │ 23     │ exit     │ 322W7JE       │
│ 267 │ 2021 │ 7     │ 28  │ 10   │ 23     │ exit     │ 0NTHK55       │
│ 268 │ 2021 │ 7     │ 28  │ 10   │ 35     │ exit     │ 1106N58       │
└─────┴──────┴───────┴─────┴──────┴────────┴──────────┴───────────────┘


SELECT * FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = "Leggett Street";

SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8;

SELECT * FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8);

SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021;
