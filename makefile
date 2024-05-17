# location: Location.cpp LocationTest.cpp Person.cpp
# 	g++ -std=c++11 -o program Location.cpp LocationTest.cpp Person.cpp
# 	./program
# 	rm -r program

# person: Person.cpp Person_test.cpp
# 	g++ -std=c++11 -o program Person.cpp Person_test.cpp
# 	./program
# 	rm -r program
	
# employee: Employee.cpp Employee_test.cpp Person.cpp
# 	g++ -std=c++11 -o program Employee.cpp Employee_test.cpp Person.cpp
# 	./program
# 	rm -r program

# customer: Customer.cpp Customer_test.cpp Person.cpp
# 	g++ -std=c++11 -o program Customer.cpp Customer_test.cpp Person.cpp
# 	./program
# 	rm -r program

# software: Software.cpp Software_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program Software.cpp Software_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# finances: Finances.cpp Finances_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program Finances.cpp Finances_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# design: Design.cpp Design_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program Design.cpp Design_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# manufacturing: Manufacturing.cpp Manufacturing_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program Manufacturing.cpp Manufacturing_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# humanresources: HumanResources.cpp HumanResources_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program HumanResources.cpp HumanResources_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# researchdevelopment: ResearchDev.cpp ResearchDev_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program ResearchDev.cpp ResearchDev_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# sales: Sales.cpp Sales_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program Sales.cpp Sales_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program

# marketing: Marketing.cpp Marketing_test.cpp Employee.cpp Person.cpp
# 	g++ -std=c++11 -o program Marketing.cpp Marketing_test.cpp Employee.cpp Person.cpp
# 	./program
# 	rm -r program



# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name
TARGET = program

# Source files
SRCS = Manager.cpp Manager_test.cpp Person.cpp Employee.cpp

# Build and run tests
.PHONY: all

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET)

# Clean rule
.PHONY: clean

clean:
	 rm $(TARGET)