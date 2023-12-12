/* v0.0.1 Initialization Of Schema */
/* Creating User Schema */

CREATE USER c##learn_c IDENTIFIED BY password;
-- DROP USER c##learn_c

/* Granting Required Privileges  */
GRANT CONNECT, RESOURCE TO c##learn_c;

-- CONNECT c##learn_c/password
-- SHOW USER; 

-- SELECT tname FROM tab;