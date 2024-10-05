-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime_scene_reports table to look for a crime scene report that matches the date and location of the crime
SELECT *
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- 3 witnesses, crime took place at 10.15am at Humphrey Street bakery

-- interviews table
SELECT *
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;

-- within 10 minutes of theft, thief got into a car at bakery parking lot, thief withdrew money at the ATM on Leggett Street earlier in the morning, thief left the bakery and called someone and talked less than a minute,
-- plan to take the earliest flight out of fiftyville tomorrow, ask the person on the phone to buy ticket

-- bakery_security_logs table
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND(minute BETWEEN 15 AND 25);

-- atm_transactions table
SELECT account_number
FROM atm_transactions
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- phone_calls table
SELECT caller,receiver
FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60;

-- flights table
SELECT *
FROM flights
WHERE year = 2023
AND month = 7
AND day = 29
AND hour = 8;


-- airports table to find the city the thief escaped to
SELECT *
FROM airports
WHERE id = 4;





