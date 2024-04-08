to generate the protofiles: 
    * create the build folder 
    * create a folder called proto/ insde the build folder 
    * from the main folder, call the command below:
        protoc --proto_path=. --cpp_out=build/proto helloworld.proto
    
    * cd build
    * cmake .. 
    * cmake --build .


There is one class generated per message in the proto file. 
two main methods of the class are
    * bool ParseFromString(const std::string& data);
    * bool SerializeToString(std::string * output);

To Debug, use
    * std::string DebugString(); // returns a string that is a text representation of the proto message
    
Other methods include: 
    * Rule of 5 methods
    * swap 
    * UnknownFieldSet()
    * mutable_unknown_fields()

For example: 
    message MyMessage {
    string false = 1; // will be appended by a _ , it will become false_
    string myFalse = 2;
    }
will generate:
    void clear_false_() ;
    const std::string& false_() const;  
    void set_false_(Arg_&& arg, Args_... args);
    std::string* mutable_false_();
    PROTOBUF_NODISCARD std::string* release_false_();
    void set_allocated_false_(std::string* ptr);

    void clear_myfalse() ;
    const std::string& myfalse() const;
    void set_myfalse(Arg_&& arg, Args_... args);
    std::string* mutable_myfalse();
    PROTOBUF_NODISCARD std::string* release_myfalse();
    void set_allocated_myfalse(std::string* ptr);

A group of accessor fields are created for each field: 
for     
    optional int32 foo = 1;
the compiler will generate: 
    * bool has_foo() const 
    * int32 foo() const  // returns current value 
    * void set_foo(int32 value) 
    * coid clear_foo() 

