-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime_scene_reports table to look for a crime scene report that matches the date and location of the crime
SELECT *
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- 3 witnesses, crime took place at 10.15am at Humphrey Street bakery

-- bakery_security_logs table
SELECT *
FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND minute = 15;

