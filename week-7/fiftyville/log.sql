-- Keep a log of all SQL queries executed while solving the mystery.

-- Explore the crime scene report
SELECT *
FROM crime_scene_reports
WHERE year = 2025
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street';

-- Review witness statements for clues
SELECT name, transcript
FROM interviews
WHERE year = 2025
  AND month = 7
  AND day = 28;

-- Find suspects who exited the bakery parking lot shortly after the theft
SELECT p.name
FROM bakery_security_logs b
JOIN people p
  ON b.license_plate = p.license_plate
WHERE b.year = 2025
  AND b.month = 7
  AND b.day = 28
  AND b.hour = 10
  AND b.minute BETWEEN 15 AND 25
  AND b.activity = 'exit';

-- Find people who withdrew money from the Leggett Street ATM
SELECT DISTINCT p.name
FROM atm_transactions a
JOIN bank_accounts ba
  ON a.account_number = ba.account_number
JOIN people p
  ON p.id = ba.person_id
WHERE a.year = 2025
  AND a.month = 7
  AND a.day = 28
  AND a.atm_location = 'Leggett Street'
  AND a.transaction_type = 'withdraw';

-- Find people who made phone calls lasting less than one minute
SELECT DISTINCT p.name
FROM phone_calls pc
JOIN people p
  ON p.phone_number = pc.caller
WHERE pc.year = 2025
  AND pc.month = 7
  AND pc.day = 28
  AND pc.duration < 60;

-- Find the earliest flight departing on July 29
SELECT *
FROM flights
WHERE year = 2025
  AND month = 7
  AND day = 29
ORDER BY hour, minute
LIMIT 1;

-- Find all passengers on that flight
SELECT p.name
FROM passengers pa
JOIN people p
  ON pa.passport_number = p.passport_number
WHERE pa.flight_id = 36;

-- Intersect all clues
-- The only person who appears in:
-- 1. The bakery exit records
-- 2. The ATM withdrawal records
-- 3. The short phone call records
-- 4. The passenger list of the earliest flight
-- is Bruce.

-- Determine the city to which the thief escaped
SELECT a.city
FROM flights f
JOIN airports a
  ON f.destination_airport_id = a.id
WHERE f.id = 36;

-- Identify the accomplice who helped the thief escape
SELECT p2.name
FROM phone_calls pc
JOIN people p1
  ON p1.phone_number = pc.caller
JOIN people p2
  ON p2.phone_number = pc.receiver
WHERE p1.name = 'Bruce'
  AND pc.year = 2025
  AND pc.month = 7
  AND pc.day = 28
  AND pc.duration < 60;
