create database JWGL;
use JWGL;
create table student( 
	Sno char(8) NOT NULL Primary Key,
	Sname varchar(10) NOT NULL,
	Sex char(2) DEFAULT '男' NOT NULL,
	Age tinyint DEFAULT 20 NOT NULL,
	Phonenumber char(12) NULL,
	Sdept varchar(20) NOT NULL) ;

create table Course(
	Cno char(10) NOT NULL Primary Key,
	Cname varchar(20) NOT NULL,
	Total_perior tinyint  DEFAULT 64,
	Week_perior tinyint DEFAULT 4,
 	credit tinyint NOT NULL DEFAULT 4,
 	Pcno char(10) NULL) ;

create table SC(
	Sno char(8) NOT NULL,
	Cno char(10) NOT NULL,
	Grade tinyint NULL) ;

alter table SC add constraint fk_class_Sno foreign key(Sno) references student(Sno);
alter table SC add constraint fk_class_Cno foreign key(Cno) references Course(Cno);

INSERT INTO student(Sno,Sname,Sex,Age,Phonenumber,Sdept) Values
	(1,"张三","男",17,'13001011111','A1'),
	(2,"李四","男",16,'14101011111','A2');
UPDATE student SET Phonenumber = '13899888899' WHERE Sname LIKE '李%';

DELETE FROM student WHERE Sname LIKE '%三';

