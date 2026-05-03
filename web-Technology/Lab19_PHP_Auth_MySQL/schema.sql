-- Run this in your MySQL database 
CREATE DATABASE IF NOT EXISTS webtech_lab;
USE webtech_lab;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    email VARCHAR(100)
);

-- Insert a default user (password is 'password123')
-- For simplicity, using plain text. IN REALITY, ALWAYS USE password_hash()
INSERT INTO users (username, password, email) VALUES ('admin', 'password123', 'admin@test.com');\n