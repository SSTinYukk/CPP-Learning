 CREATE TABLE Customers(
    CustomerID  int PRIMARY  KEY AUTO_INCREMENT,
    CName  varchar(8)  NOT  NULL ,
    Address  varchar(50),
    City  varchar(10),
    Tel  varchar(20)  UNIQUE,
    Company  varchar(50),
    Birthday  DATETIME,
    Type  tinyint  DEFAULT 1);

CREATE TABLE Goods (

    GoodsID int PRIMARY  KEY ,
    GoodsName  varchar(20)  NOT  NULL,
    Price  int,
    Description  varchar(200),
    Storage   int,
    Provider  varchar(50),
    Status  tinyint  DEFAULT 0);

CREATE TABLE Orders (
    OrderID  int  AUTO_INCREMENT  PRIMARY  KEY ,
    GoodsID  int  NOT NULL  REFERENCES Goods(GoodsID)  ON  DELETE CASCADE,
    CustomerID  int  NOT NULL,
    FOREIGN KEY(CustomerID) REFERENCES Customers (CustomerID)  ON  UPDATE  CASCADE
    ON DELETE NO ACTION,
    Quantity  int  NOT NULL  CONSTRAINT  ),
    OrderSum  money  NOT NULL,
    OrderDate  datetime  DEFAULT CURDATE() );