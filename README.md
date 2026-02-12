Smart Vending Machine (C++)

A console-based Smart Vending Machine System built in C++.
This project simulates a real vending machine where users can:

Select items

Insert money

Receive change

Manage stock (Admin Mode)

📌 Features
🛒 User Features

Display vending machine menu with:

Item number

Item name

Price

Stock status

Purchase multiple quantities of items

Automatic change calculation

Out-of-stock handling

Input validation for quantity and payment

🔐 Admin Features

Password-protected refill system

View current stock

Refill a specific item

Refill all items to maximum stock (50 units)

🧾 Available Items
Item No	Item Name	Price (Rs)
1	Chips	50
2	Chocolate	120
3	Cold Drink	80
4	Juice	70
5	Biscuit	40
6	Water Bottle	30
7	Energy Drink	150
8	Candy	20
🛠 Technologies Used

C++

Standard Library:

<iostream>

<iomanip>

▶️ How to Compile and Run
🔹 Using g++
g++ vending_machine.cpp -o vending_machine
./vending_machine

🔹 Using any C++ IDE

Open the file

Compile

Run the program

🔑 Admin Access

To enter Admin Refill Mode:

Select option 9 from the main menu

Enter password:

admin123


⚠️ Note: This is a simple hardcoded password for demonstration purposes.

📂 Project Structure
Smart-Vending-Machine/
│
├── vending_machine.cpp
└── README.md

💡 Concepts Used

Functions

Arrays

Loops (for, do-while)

Conditional statements (if-else)

Input/Output handling

Basic stock management logic

Password authentication system

🚀 Future Improvements

File handling to store stock permanently

Better UI formatting

Admin password encryption

Object-Oriented Programming (OOP) version

Payment system simulation (UPI/Card)

📄 License

This project is for educational purposes.# vanding-machine-c-
