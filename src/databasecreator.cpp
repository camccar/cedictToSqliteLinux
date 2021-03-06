#include "databasecreator.h"
#include <fstream>

#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>


void databasecreator::createDatabaseFile() {
	std::string tablename = "cedict";
	try {

		std::string dest = "cedict.db3";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS cedict");
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY, pinyin adLongVarWChar,pinyinnumbered adLongVarWChar,simplified adLongVarWChar ,traditional adLongVarWChar,basicpinyin Text,colorid INTEGER, FOREIGN KEY(colorid) REFERENCES colors(id) )");
		std::cout << "Created cedict table and database" << std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void databasecreator::createSettingsTable() {
	std::string tablename = "settings";
	try{
		std::string dest = "cedict.db3";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,name TEXT, value TEXT)");
		std::cout << "Finished Creating "+ tablename+" table "<< std::endl;
		transaction.commit();
	}
	catch (std::exception & e){
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void databasecreator::createFavoritesTable() {
	try {
		std::cout << "Creating favorites table" << std::endl;
		std::string dest = "cedict.db3";
		std::string tablename = "favorites";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS favorites");
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,notes TEXT,cedictid INTEGER, FOREIGN KEY(cedictid) REFERENCES cedict(id) )");
		std::cout << "Finished Creating favorites table "<< std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

}
void databasecreator::createtagnameTable() {
	try {
		std::cout << "Creating tagnames table" << std::endl;
		std::string dest = "cedict.db3";
		std::string tablename = "tagnames";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS tagnames");
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,name TEXT)");
		std::cout << "Finished Creating tagnames table "<< std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {

		std::cout << "exception: " << e.what() << std::endl;
	}
}
void databasecreator::createcolorsTable() {
try {
		std::cout << "Creating colors table" << std::endl;
		std::string dest = "cedict.db3";
		std::string tablename = "colors";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,color Text,name Text)");
		std::cout << "Finished Creating "+ tablename+" table "<< std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}
void databasecreator::createfavoritetagsTable(){
	try {
		std::cout << "Creating tagnames table" << std::endl;
		std::string dest = "cedict.db3";
		std::string tablename = "favoritetags";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,tagid INTEGER,favoriteid INTEGER,FOREIGN KEY(tagid) REFERENCES tagnames(id), FOREIGN KEY(favoriteid) REFERENCES favorites(id))");
		std::cout << "Finished Creating "+tablename+" table "<< std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void databasecreator::createflashcardsTable(){
	try {
		std::string tablename = "flashcarddeck";
		std::string dest = "cedict.db3";
		std::cout << "Creating "<< tablename <<" table" << std::endl;
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,name TEXT,description TEXT,front TEXT,back TEXT)");
		std::cout << "Finished Creating "+tablename+" table "<< std::endl;
		transaction.commit();
	}

	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}


void databasecreator::createflashcardcarddataTable(){
	try {
		std::string tablename = "flashcarddata";
		std::string dest = "cedict.db3";
		std::cout << "Creating "<< tablename <<" table" << std::endl;
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,flashcarddeckid INTEGER,cedictid INTEGER,LastEditTime DATETIME DEFAULT CURRENT_TIMESTAMP,lastanswercorrect INTEGER,FOREIGN KEY(flashcarddeckid) REFERENCES flashcarddeck(id), FOREIGN KEY(cedictid) REFERENCES cedict(id))");
		std::cout << "Finished Creating "+tablename+" table "<< std::endl;
		transaction.commit();
	}

	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}
void databasecreator::createEnumTable(){
	try {
		std::string tablename = "enums";
		std::string dest = "cedict.db3";
		std::cout << "Creating "<< tablename <<" table" << std::endl;
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,name TEXT,description TEXT)");
		std::cout << "Finished Creating "+tablename+" table "<< std::endl;
		transaction.commit();
	}

	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void databasecreator::createDefinitionsTable() {
	try {
		std::cout << "Creating Definitions table" << std::endl;
		std::string dest = "cedict.db3";
		std::string tablename = "definitions";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS definitions");
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,definition adLongVarWChar,cedictid INTEGER, FOREIGN KEY(cedictid) REFERENCES cedict(id) )");
		std::cout << "Finished Creating favorites table " << std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

}
void databasecreator::createSearchHistoryTable(){
	try {
		std::string tablename = "searchhistory";
		std::cout << "Creating "<<tablename<<" table" << std::endl;
		std::string dest = "cedict.db3";
		
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);
		db.exec("DROP TABLE IF EXISTS "+tablename);
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,searchterm adLongVarWChar, Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP)");
		std::cout << "Finished Creating "<<tablename<<" table " << std::endl;
		transaction.commit();
	}
	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void databasecreator::createdatabase(std::vector<cedict*> bag) {

	std::string tablename = "cedict";

	
	
	std::cout << "Done setting bag" << std::endl;

	std::cout << "Begin database creation" << std::endl;

	createDatabaseFile();
	createFavoritesTable();
	createtagnameTable();
	createfavoritetagsTable();
	createDefinitionsTable();
	createcolorsTable();
	createtagnameTable();
	createSearchHistoryTable();
	createSettingsTable();
	createflashcardsTable();
	createflashcardcarddataTable();
	createEnumTable();
	int counter = 1;
	std::cout << "Begin inserting all that into new table" << std::endl;
	try {




		std::string dest = "cedict.db3";
		SQLite::Database    db(dest, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
		SQLite::Transaction transaction(db);





		for (auto it = bag.begin(); it < bag.end(); ++it) {
			std::shared_ptr<SQLite::Statement>  query;
			query.reset(new SQLite::Statement(db, "INSERT INTO cedict (id,pinyin,pinyinnumbered,simplified,traditional,basicpinyin) VALUES(?,?,?,?,?,?)"));

			query->bind(1, counter);
			query->bind(2, (*it)->getPinyin());
			query->bind(3, (*it)->getPinyinNumbered());
			query->bind(4, (*it)->getSimplified());
			query->bind(5, (*it)->getTraditional());
			query->bind(6, (*it)->getPinyinBasic());
			while (query->executeStep())
			{
			}
			//std::cout << "Done inserting cedict now lets do definition";
			auto defs = (*it)->getDefinitions();
			for (auto ji = defs.begin(); ji < defs.end(); ++ji) {
				//insertdefinitions(*ji, counter);
				if ((*ji) != "") {
					query.reset();
					query.reset(new SQLite::Statement(db, "INSERT INTO definitions (definition,cedictid) VALUES(?,?)"));
					query->bind(1, *ji);
					query->bind(2, counter);
					while (query->executeStep())
					{
					}
				}

			}
			++counter;

		}

		//Insert Colors
		std::shared_ptr<SQLite::Statement>  query;
		query.reset();
		std::string yellow = "#E3FF1F";
		query.reset(new SQLite::Statement(db, "INSERT INTO colors (id,name,color) VALUES(1,'yellow',?)"));
		query->bind(1, yellow);
		while (query->executeStep()){}
		query.reset();
		std::string blue = "#2876FF";
		query.reset(new SQLite::Statement(db, "INSERT INTO colors (id,name,color) VALUES(2,'blue',?)"));
		query->bind(1, blue);
		while (query->executeStep()){}
		query.reset();
		std::string green = "#34FF38";
		query.reset(new SQLite::Statement(db, "INSERT INTO colors (id,name,color) VALUES(3,'green',?)"));
		query->bind(1, green);
		while (query->executeStep()){}
		std::string red = "#EB4034";
		query.reset(new SQLite::Statement(db, "INSERT INTO colors (id,name,color) VALUES(4,'red',?)"));
		query->bind(1, red);
		while (query->executeStep()){}

		std::cout << "Finished inserting " << counter << " dictonary objects" << std::endl;

		//Insert Settings
		query.reset(new SQLite::Statement(db,"INSERT INTO settings (id,name,value) VALUES(1,'hanzilabel','Simplified')"));
		while (query->executeStep()){}
		query.reset(new SQLite::Statement(db,"INSERT INTO settings (id,name,value) VALUES(2,'favoritefontsize','14')"));
		while (query->executeStep()){}
		
/*

		 "enums";
	
		db.exec("CREATE TABLE " + tablename + "(id INTEGER PRIMARY KEY,name TEXT,description TEXT)");

*/
		//Insert Enums
		query.reset(new SQLite::Statement(db,"INSERT INTO enums (id,name,description) VALUES(1,'hanzi','chinese character')"));
		while (query->executeStep()){}
		query.reset(new SQLite::Statement(db,"INSERT INTO enums (id,name,description) VALUES(2,'pinyin','chinese latin character')"));
		while (query->executeStep()){}
		query.reset(new SQLite::Statement(db,"INSERT INTO enums (id,name,description) VALUES(3,'definition','definition')"));
		while (query->executeStep()){}


		transaction.commit();
		
	}

	catch (std::exception & e) {
		std::cout << "exception: " << e.what() << std::endl;


	}


}
