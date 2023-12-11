CXX = g++
CXXFLAGS = -g -Wall -std=c++11
DEFS = # Uncomment and add your DEBUG flag here if needed

# List all your source files
SRCS = amazon.cpp user.cpp db_parser.cpp product.cpp product_parser.cpp util.cpp datastore.cpp book.cpp clothing.cpp movie.cpp

# Generate object file names from source files
OBJS = $(SRCS:.cpp=.o)

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

# Define a pattern rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@

clean:
	rm -f *.o amazon
