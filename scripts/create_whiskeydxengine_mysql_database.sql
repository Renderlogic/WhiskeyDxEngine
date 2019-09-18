/**
 * Basic SQL script to create the WhiskeyDxEngine Database and Tables.
 * Author:  John McDonnell
 * Created: Sep 18, 2019
 */

CREATE SCHEMA `WhiskeyDxEngine` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci ;

CREATE TABLE `WhiskeyDxEngine`.`icd10cm_2020_dx_codes` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `code` VARCHAR(255) NOT NULL,
  `disease` VARCHAR(500) NOT NULL,
  `insertion_date` TIMESTAMP NULL,
`38cfrbookc_va_dx_code` INT UNSIGNED NULL,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id` ASC) VISIBLE);

CREATE TABLE `icd9cm_dx_codes` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `code` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `disease` varchar(500) COLLATE utf8mb4_unicode_ci NOT NULL,
  `insertion_date` timestamp NULL DEFAULT NULL,
  `38cfrbookc_va_dx_code` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;