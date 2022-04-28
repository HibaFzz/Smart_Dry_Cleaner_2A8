--------------------------------------------------------
--  Fichier créé - jeudi-avril-28-2022   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ARTICL
--------------------------------------------------------

  CREATE TABLE "MOLKA"."ARTICL" 
   (	"REF" NUMBER, 
	"NOM_AR" VARCHAR2(20 BYTE), 
	"TYPE_AR" VARCHAR2(20 BYTE), 
	"PRIX" FLOAT(126)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENTS
--------------------------------------------------------

  CREATE TABLE "MOLKA"."CLIENTS" 
   (	"IDC" NUMBER, 
	"NOMC" VARCHAR2(40 BYTE), 
	"PRENOMC" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(40 BYTE), 
	"NUMTEL" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COMMANDE
--------------------------------------------------------

  CREATE TABLE "MOLKA"."COMMANDE" 
   (	"ID_COM" NUMBER, 
	"DATE_RECEP" DATE, 
	"DATE_LIVR" DATE, 
	"FK_CLIENT" NUMBER, 
	"FK_EMPLOYE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CONTENIR
--------------------------------------------------------

  CREATE TABLE "MOLKA"."CONTENIR" 
   (	"PRIX" FLOAT(126), 
	"QUANTITE" NUMBER, 
	"FK_AR" NUMBER, 
	"FK_COM" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYE
--------------------------------------------------------

  CREATE TABLE "MOLKA"."EMPLOYE" 
   (	"ID" NUMBER, 
	"NOMEMP" VARCHAR2(20 BYTE), 
	"PRENOMEMP" VARCHAR2(20 BYTE), 
	"DATE_NAISSANCE" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(40 BYTE), 
	"SALAIRE" NUMBER, 
	"NUM_TEL" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table HISTORIQUE
--------------------------------------------------------

  CREATE TABLE "MOLKA"."HISTORIQUE" 
   (	"ACTIVITE_H" VARCHAR2(500 BYTE), 
	"DATE_H" DATE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOGIN
--------------------------------------------------------

  CREATE TABLE "MOLKA"."LOGIN" 
   (	"USERNAME" VARCHAR2(20 BYTE), 
	"PWD" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into MOLKA.ARTICL
SET DEFINE OFF;
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('7','manteau','enfant ','4');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('1','jupe','femme','5');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('3','costume','homme','10');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('2','veste_cuir','femme','6');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('6','couette','femme','10');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('4','manteau','homme','7');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('8','robe_soiree','femme','10');
Insert into MOLKA.ARTICL (REF,NOM_AR,TYPE_AR,PRIX) values ('5','manteau','femme','7');
REM INSERTING into MOLKA.CLIENTS
SET DEFINE OFF;
Insert into MOLKA.CLIENTS (IDC,NOMC,PRENOMC,MAIL,NUMTEL) values ('404','saida','mokrani','saida@gmail.com','78963142');
Insert into MOLKA.CLIENTS (IDC,NOMC,PRENOMC,MAIL,NUMTEL) values ('14256','moolka','fz','molkafz@gmail.com','54127836');
Insert into MOLKA.CLIENTS (IDC,NOMC,PRENOMC,MAIL,NUMTEL) values ('544','saida','mokrani','mokrani@gmail..com','95589588');
Insert into MOLKA.CLIENTS (IDC,NOMC,PRENOMC,MAIL,NUMTEL) values ('11444','meriem','benkahla','benkahla@gmail.com','28713695');
Insert into MOLKA.CLIENTS (IDC,NOMC,PRENOMC,MAIL,NUMTEL) values ('4777','hiba','fz','hibafz@gmail.com','54789631');
Insert into MOLKA.CLIENTS (IDC,NOMC,PRENOMC,MAIL,NUMTEL) values ('547','omar','fz','omarfz@gmail.com','52147368');
REM INSERTING into MOLKA.COMMANDE
SET DEFINE OFF;
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('147',to_date('26/02/22','DD/MM/RR'),to_date('28/02/22','DD/MM/RR'),'544','101');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('3699',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'4777','101');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('47',to_date('26/05/22','DD/MM/RR'),to_date('29/05/22','DD/MM/RR'),'544','101');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('669',to_date('26/03/22','DD/MM/RR'),to_date('29/03/22','DD/MM/RR'),'4777','101');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('6655',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'4777','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('69',to_date('26/02/22','DD/MM/RR'),to_date('28/02/22','DD/MM/RR'),'4777','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('456',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('468',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'4777','101');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('1789',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('4785',to_date('27/04/22','DD/MM/RR'),to_date('30/04/22','DD/MM/RR'),'404','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('14562',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('4788',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('68595',to_date('27/04/22','DD/MM/RR'),to_date('30/04/22','DD/MM/RR'),'404','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('66695',to_date('26/01/22','DD/MM/RR'),to_date('29/01/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('98',to_date('25/01/22','DD/MM/RR'),to_date('28/01/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('889',to_date('26/04/22','DD/MM/RR'),to_date('29/04/22','DD/MM/RR'),'544','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('65',to_date('28/06/22','DD/MM/RR'),to_date('01/06/22','DD/MM/RR'),'404','100');
Insert into MOLKA.COMMANDE (ID_COM,DATE_RECEP,DATE_LIVR,FK_CLIENT,FK_EMPLOYE) values ('134',to_date('28/04/22','DD/MM/RR'),to_date('01/05/22','DD/MM/RR'),'404','100');
REM INSERTING into MOLKA.CONTENIR
SET DEFINE OFF;
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('10','2','8','47');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('10','2','8','69');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('10','1','8','147');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('10','1','8','669');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('12','2','6','98');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('15','3','3','47');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('10','2','4','669');
Insert into MOLKA.CONTENIR (PRIX,QUANTITE,FK_AR,FK_COM) values ('0','0','1','47');
REM INSERTING into MOLKA.EMPLOYE
SET DEFINE OFF;
Insert into MOLKA.EMPLOYE (ID,NOMEMP,PRENOMEMP,DATE_NAISSANCE,MAIL,SALAIRE,NUM_TEL) values ('100','hiba','fz','sam. janv. 1 2000','hibafz@gmail.com','400','789321456');
Insert into MOLKA.EMPLOYE (ID,NOMEMP,PRENOMEMP,DATE_NAISSANCE,MAIL,SALAIRE,NUM_TEL) values ('5554','khouloud','bousseha','sam. janv. 1 2000','boussehakhouloud@???gmail.com','1500','78456123');
Insert into MOLKA.EMPLOYE (ID,NOMEMP,PRENOMEMP,DATE_NAISSANCE,MAIL,SALAIRE,NUM_TEL) values ('1478','Ahmed','Fezzani','jeu. janv. 1 1970','ahmed@gmail.com','500','98511475');
Insert into MOLKA.EMPLOYE (ID,NOMEMP,PRENOMEMP,DATE_NAISSANCE,MAIL,SALAIRE,NUM_TEL) values ('213','firas','chargui','sam. janv. 1 2000','chargui.firas@gmail.com','500','52147896');
Insert into MOLKA.EMPLOYE (ID,NOMEMP,PRENOMEMP,DATE_NAISSANCE,MAIL,SALAIRE,NUM_TEL) values ('101','molka','fezzani','sam. janv. 1 2000','molka@gmail.com','500','56045147');
REM INSERTING into MOLKA.HISTORIQUE
SET DEFINE OFF;
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression employe',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification employe',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification employe',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Client',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Article',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer une commande deja passée',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('26/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Client',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Client',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Client',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Client',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modifier Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer une commande deja passée',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Suppression employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Modification employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Commande',to_date('27/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Passer Commande',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer une commande deja passée',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Commande',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Commande',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Commande',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Insertion employe',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Ajout Article',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Supprimer Article',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Employe',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('28/04/22','DD/MM/RR'));
Insert into MOLKA.HISTORIQUE (ACTIVITE_H,DATE_H) values ('Login Admin',to_date('28/04/22','DD/MM/RR'));
REM INSERTING into MOLKA.LOGIN
SET DEFINE OFF;
Insert into MOLKA.LOGIN (USERNAME,PWD) values ('admin','admin');
Insert into MOLKA.LOGIN (USERNAME,PWD) values ('user','user');
--------------------------------------------------------
--  DDL for Index ARTICLE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MOLKA"."ARTICLE_PK" ON "MOLKA"."ARTICL" ("REF") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENTS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MOLKA"."CLIENTS_PK" ON "MOLKA"."CLIENTS" ("IDC") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MOLKA"."CLIENT_PK" ON "MOLKA"."COMMANDE" ("ID_COM") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CONTENIR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MOLKA"."CONTENIR_PK" ON "MOLKA"."CONTENIR" ("FK_AR", "FK_COM") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYÉ_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MOLKA"."EMPLOYÉ_PK" ON "MOLKA"."EMPLOYE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ARTICL
--------------------------------------------------------

  ALTER TABLE "MOLKA"."ARTICL" MODIFY ("REF" NOT NULL ENABLE);
  ALTER TABLE "MOLKA"."ARTICL" ADD CONSTRAINT "ARTICLE_PK" PRIMARY KEY ("REF")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table CLIENTS
--------------------------------------------------------

  ALTER TABLE "MOLKA"."CLIENTS" MODIFY ("IDC" NOT NULL ENABLE);
  ALTER TABLE "MOLKA"."CLIENTS" ADD CONSTRAINT "CLIENTS_PK" PRIMARY KEY ("IDC")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table COMMANDE
--------------------------------------------------------

  ALTER TABLE "MOLKA"."COMMANDE" MODIFY ("ID_COM" NOT NULL ENABLE);
  ALTER TABLE "MOLKA"."COMMANDE" ADD CONSTRAINT "COMMANDE_PK" PRIMARY KEY ("ID_COM")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table CONTENIR
--------------------------------------------------------

  ALTER TABLE "MOLKA"."CONTENIR" MODIFY ("FK_AR" NOT NULL ENABLE);
  ALTER TABLE "MOLKA"."CONTENIR" MODIFY ("FK_COM" NOT NULL ENABLE);
  ALTER TABLE "MOLKA"."CONTENIR" ADD CONSTRAINT "CONTENIR_PK" PRIMARY KEY ("FK_AR", "FK_COM")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table EMPLOYE
--------------------------------------------------------

  ALTER TABLE "MOLKA"."EMPLOYE" MODIFY ("ID" NOT NULL ENABLE);
  ALTER TABLE "MOLKA"."EMPLOYE" ADD CONSTRAINT "EMPLOYE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table COMMANDE
--------------------------------------------------------

  ALTER TABLE "MOLKA"."COMMANDE" ADD CONSTRAINT "FK1" FOREIGN KEY ("FK_CLIENT")
	  REFERENCES "MOLKA"."CLIENTS" ("IDC") ENABLE;
  ALTER TABLE "MOLKA"."COMMANDE" ADD CONSTRAINT "FK2" FOREIGN KEY ("FK_EMPLOYE")
	  REFERENCES "MOLKA"."EMPLOYE" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table CONTENIR
--------------------------------------------------------

  ALTER TABLE "MOLKA"."CONTENIR" ADD CONSTRAINT "CONTENIR_FK1" FOREIGN KEY ("FK_AR")
	  REFERENCES "MOLKA"."ARTICL" ("REF") ENABLE;
  ALTER TABLE "MOLKA"."CONTENIR" ADD CONSTRAINT "CONTENIR_FK2" FOREIGN KEY ("FK_COM")
	  REFERENCES "MOLKA"."COMMANDE" ("ID_COM") ENABLE;
