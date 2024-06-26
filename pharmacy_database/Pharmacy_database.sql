CREATE DATABASE pharmacy;
USE pharmacy;
CREATE TABLE pharmacist (
  pharmacist_id VARCHAR(6) PRIMARY KEY,
  phf_name VARCHAR(20),
  phl_name VARCHAR(20),
  age INT,
  salary FLOAT,
  gender VARCHAR(6)
);

CREATE TABLE customer (
  customer_id INT PRIMARY KEY,
  first_name VARCHAR(15),
  last_name VARCHAR(15),
  prescription VARCHAR(100),
  cpharmacist_id VARCHAR(6),
  FOREIGN KEY (cpharmacist_id) REFERENCES pharmacist(pharmacist_id)
);

CREATE TABLE manager (
  manager_id VARCHAR(6) PRIMARY KEY,
  first_name VARCHAR(25),
  last_name VARCHAR(25),
  gender VARCHAR(6)
);

CREATE TABLE store (
  store_id VARCHAR(20) PRIMARY KEY,
  item_number INT,
  smanager_id VARCHAR(6),
  FOREIGN KEY (smanager_id) REFERENCES manager(manager_id)
);

CREATE TABLE item (
  item_code VARCHAR(12) PRIMARY KEY,
  item_name VARCHAR(50),
  sold_date DATE,
  exp_date DATE,
  istore_id VARCHAR(20),
  ipharmacist_id VARCHAR(6),
  icustomer_id int,
  FOREIGN KEY (istore_id) REFERENCES store(store_id),
 FOREIGN KEY (icustomer_id) REFERENCES customer(customer_id),
  FOREIGN KEY (ipharmacist_id) REFERENCES pharmacist(pharmacist_id)
);

CREATE TABLE item_type (
  type_item VARCHAR(12),
  type_item_code VARCHAR(12),
  FOREIGN KEY (type_item_code) REFERENCES item(item_code)
);

CREATE TABLE cashier (
  cashier_id VARCHAR(6) PRIMARY KEY,
  first_name VARCHAR(12),
  last_name VARCHAR(25),
  gender VARCHAR(6)
);

CREATE TABLE billing (
  billing_code VARCHAR(12) PRIMARY KEY,
  total_amount INT,
  bitem_code VARCHAR(12),
  bcustomer_id INT,
  bcasher_id VARCHAR(6),
  FOREIGN KEY (bitem_code) REFERENCES item(item_code),
  FOREIGN KEY (bcustomer_id) REFERENCES customer(customer_id),
  FOREIGN KEY (bcasher_id) REFERENCES cashier(cashier_id)
);

  