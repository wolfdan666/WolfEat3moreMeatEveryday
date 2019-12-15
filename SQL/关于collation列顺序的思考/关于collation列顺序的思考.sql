CREATE TABLE `component` (
  `pno` varchar(10) NOT NULL,
  `pname` varchar(50) DEFAULT NULL,
  `color` varchar(20) DEFAULT NULL,
  `weight` int(11) DEFAULT NULL,
  PRIMARY KEY (`pno`)
);

CREATE TABLE `supplier` (
  `sno` varchar(10) NOT NULL,
  `sname` varchar(50) DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `city` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`sno`)
);

DROP TABLE IF EXISTS `project`;
CREATE TABLE `project` (
  `jno` varchar(10) NOT NULL,
  `jname` varchar(50) DEFAULT NULL,
  `city` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`jno`)
);


CREATE TABLE `support` (
  `sno` varchar(10) NOT NULL,
  `pno` varchar(10) NOT NULL,
  `jno` varchar(10) NOT NULL,
  `qty` int(11) DEFAULT NULL,
  PRIMARY KEY (`sno`,`pno`,`jno`),
  CONSTRAINT `support_supplier` FOREIGN KEY (`sno`) REFERENCES `supplier` (`sno`) ON UPDATE CASCADE,
  CONSTRAINT `support_component` FOREIGN KEY (`pno`) REFERENCES `component` (`pno`) ON UPDATE CASCADE,
  CONSTRAINT `support_project` FOREIGN KEY (`jno`) REFERENCES `project` (`jno`) ON UPDATE CASCADE
);

-- 一直报错ERROR 1215 (HY000): Cannot add foreign key constraint
-- 按照zy给我的sql文件中一条条插入是对的,但是不知道这里为什么错了啊

-- Cannot find an index in the referenced table where the
-- referenced columns appear as the first columns, or column types
-- in the table and the referenced table do not match for constraint.
-- Note that the internal storage type of ENUM and SET changed in
-- tables created with >= InnoDB-4.1.12, and such columns in old tables
-- cannot be referenced by such columns in new tables

-- foreign定义规则排查是对的
-- https://stackoverflow.com/questions/18930084/mysql-error-1215-hy000-cannot-add-foreign-key-constraint

-- 学会了`SHOW ENGINE INNODB STATUS;`

-- 后面又上了Stack overflow,发现是因为COLLATE(列的排序规则的问题)
-- https://stackoverflow.com/questions/33948349/mysql-cannot-add-foreign-key-1215

-- 因此改成如下SQL

DROP TABLE IF EXISTS `component`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `component` (
  `pno` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `pname` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `color` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `weight` int(11) DEFAULT NULL,
  PRIMARY KEY (`pno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `project` (
  `jno` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `jname` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `city` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`jno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `supplier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `supplier` (
  `sno` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `sname` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `city` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `support`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `support` (
  `sno` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `pno` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `jno` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `qty` int(11) DEFAULT NULL,
  PRIMARY KEY (`sno`,`pno`,`jno`),
  KEY `pno` (`pno`),
  KEY `jno` (`jno`),
  CONSTRAINT `support_ibfk_1` FOREIGN KEY (`sno`) REFERENCES `supplier` (`sno`) ON UPDATE CASCADE,
  CONSTRAINT `support_ibfk_2` FOREIGN KEY (`pno`) REFERENCES `component` (`pno`) ON UPDATE CASCADE,
  CONSTRAINT `support_ibfk_3` FOREIGN KEY (`jno`) REFERENCES `project` (`jno`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
