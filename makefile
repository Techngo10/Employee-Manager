# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

.PHONY: customer

customer:
	$(CXX) $(CXXFLAGS) -o customer Customer_test.cpp Employee.cpp Person.cpp Customer.cpp
	./customer

.PHONY: design

design:
	$(CXX) $(CXXFLAGS) -o design Design_test.cpp Employee.cpp Person.cpp Design.cpp
	./design

.PHONY: employee

employee:
	$(CXX) $(CXXFLAGS) -o employee EmployeeTest.cpp Employee.cpp Person.cpp 
	./employee

.PHONY: finances

finances:
	$(CXX) $(CXXFLAGS) -o finances Finances_test.cpp Employee.cpp Person.cpp Finances.cpp
	./finances

.PHONY: humanresources

humanresources:
	$(CXX) $(CXXFLAGS) -o humanresources HumanResources_test.cpp Employee.cpp Person.cpp HumanResources.cpp
	./humanresources

.PHONY: investor

investor:
	$(CXX) $(CXXFLAGS) -o investor Investor_test.cpp Person.cpp Investor.cpp
	./investor

.PHONY: location

location:
	$(CXX) $(CXXFLAGS) -o location Location_test.cpp Functions.cpp Employee.cpp Person.cpp Customer.cpp Design.cpp Finances.cpp HumanResources.cpp Investor.cpp Manager.cpp Manufacturing.cpp Marketing.cpp ResearchDev.cpp Sales.cpp Software.cpp Supplier.cpp VIP.cpp Location.cpp
	./location

.PHONY: manager

manager:
	$(CXX) $(CXXFLAGS) -o manager Manager_test.cpp Employee.cpp Person.cpp Manager.cpp
	./manager

.PHONY: manufacturing

manufacturing:
	$(CXX) $(CXXFLAGS) -o manufacturing Manufacturing_test.cpp Employee.cpp Person.cpp Manufacturing.cpp
	./manufacturing

.PHONY: marketing

marketing:
	$(CXX) $(CXXFLAGS) -o marketing Marketing_test.cpp Employee.cpp Person.cpp Marketing.cpp
	./marketing

.PHONY: person

person:
	$(CXX) $(CXXFLAGS) -o person Person_test.cpp Person.cpp
	./person

.PHONY: ResearchDev

researchdev:
	$(CXX) $(CXXFLAGS) -o researchdev ResearchDev_test.cpp Employee.cpp Person.cpp ResearchDev.cpp
	./researchdev

.PHONY: sales

sales:
	$(CXX) $(CXXFLAGS) -o sales Sales_test.cpp Employee.cpp Person.cpp Sales.cpp
	./sales

.PHONY: software

software:
	$(CXX) $(CXXFLAGS) -o software Software_test.cpp Employee.cpp Person.cpp Software.cpp
	./software

.PHONY: supplier

supplier:
	$(CXX) $(CXXFLAGS) -o supplier Supplier_test.cpp Person.cpp Supplier.cpp
	./supplier

.PHONY: vip

vip:
	$(CXX) $(CXXFLAGS) -o vip VIP_test.cpp Customer.cpp Person.cpp VIP.cpp
	./vip

# Clean rule

.PHONY: clean

clean:
	 rm -f a.out customer design employee finances humanresources investor location manager manufcaturing marketing person researchdev sales software supplier vip