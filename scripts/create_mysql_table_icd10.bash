#!/bin/bash
# 
# File:   create_mysql_table_icd10.bash
# Author: Renderlogic, Inc. || John McDonnell.
#
# Created on Sep 17, 2019, 10:40:32 PM
#
# Simple Bash Script to create basic ICD MySQL table
# and parse the icd10cm_codes_2020.txt or any other icd file into.
# Just simply modify the variables.
ICD_FILE_NAME="icd10cm_codes_2020.txt"
ICD_SOURCE_FILE_PATH="../data/${ICD_FILE_NAME}"

# SECURITY WARNING: REMOVE THESE VALUES BEFORE COMMITING TO REPO 
MYSQL_USERNAME="WhiskeyDxEngine" 
MYSQL_PASSWORD="WhiskeyDxEngine"
mysql -u ${MYSQL_USERNAME} -p ${MYSQL_PASSWORD}

# un-comment create statement below to create a the schema if needed.
# CREATE SCHEMA `WhiskeyDxEngine` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci ;
