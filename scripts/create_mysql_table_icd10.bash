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

# SECURITY WARNING: REMOVE THESE VALUES BEFORE COMMITING TO REPO IN REAL PRODUCTION ENVIRONMENTS
# VALUES BELOW INCLUDING PASSWORD ARE JUST TEMPORARY THROW-AWAY VALUES INCLUDING -> @Wh1$k3yDx3ng1n3@.
# I INTENTIONALLY LEFT THIS SINGLE-USE DEV ENVIRONMENT PW IN HERE FOR MEMORY SAKES.
MYSQL_USERNAME="WhiskeyDxEngine" 
MYSQL_PASSWORD="@Wh1$k3yDx3ng1n3@"
MYSQL_DATABASE="WhiskeyDxEngine"
mysql -u ${MYSQL_USERNAME} -p${MYSQL_PASSWORD} -D ${MYSQL_DATABASE}
