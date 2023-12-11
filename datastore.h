#ifndef DATASTORE_H
#define DATASTORE_H

#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include <map>

class DataStore {
public:
    virtual ~DataStore() { }

    virtual void addProduct(Product* p) = 0;
    virtual void addUser(User* u) = 0;
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type) = 0;
    virtual void dump(std::ostream& ofile) = 0;
    virtual void viewCart(const std::string& username) = 0;
    virtual void buyCart(const std::string& username) = 0;
};

class MyDataStore : public DataStore {
private:
    std::vector<Product*> products;
    std::vector<User*> users;
    std::map<std::string, std::vector<Product*>> carts;
    std::map<std::string, std::set<Product*>> keywordIndex;

public:
    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;
    void viewCart(const std::string& username) override;
    void buyCart(const std::string& username) override;

private:
    void indexProduct(Product* p);
};

#endif
