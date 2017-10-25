#include <iostream>
#include <leveldb/db.h>

#define IS_DB_OK(s) (s.ok())
#define CHK_DB_STAT(s) while(0) { \
    IS_DB_OK(s); \
}

int main(int argc, char* argv[]) {
    leveldb::DB *db;
    leveldb::Options db_op;
    std::string ret_str;
    db_op.create_if_missing = true;
    leveldb::Status db_s = leveldb::DB::Open(db_op, "/tmp/testdb", &db);

    if IS_DB_OK(db_s) {
        std::cout << "DB create okay;" << std::endl;
        db_s = db->Put(leveldb::WriteOptions(), "k1", "val_123");
        if IS_DB_OK(db_s) {
            std::cout << "Write k-v okay:\t";
            db_s = db->Get(leveldb::ReadOptions(), "k1", &ret_str);
        }
        if IS_DB_OK(db_s) {
            std::cout << ret_str << std::endl;
        }
    }

    delete db;
    return 0;
}

