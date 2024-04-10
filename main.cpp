#include <iostream>
#include <google/protobuf/arena.h> 
#include "build/proto/helloworld.pb.h"

using helloworld::Person;
using helloworld::People;
using helloworld::Corpus;

int main() {
    Person p1;
    p1.set_name("Kaveh");
    p1.set_id(1);
    p1.set_email("kaveh.nematipour@outlook.com");

    std::string data; 
    p1.SerializeToString(&data); // Write from p1 to the buffer
    p1.ParseFromString(data); // Read from the buffer and set the values fot fields in p1
    std::cout << p1.DebugString();
    std:: cout << "This is the name of the user: " << p1.name() << "\n"; // reading data items 

    People pp1;
    pp1.add_myfriends()->CopyFrom(p1); // using repeated fields

    Person p2; 
    p2.set_name("Seda");
    p2.set_id(2);
    p2.set_email("seda.nematipour@outlook.com");
    pp1.add_myfriends()->CopyFrom(p2); // adding another member to repeated fields

    auto s1 {p1.mutable_name()}; // we have mutable getters that return a pointer to the actual data

    std::cout << pp1.myfriends(1).DebugString();
    std::cout << pp1.myfriends().size() << std::endl; 

    Corpus c1 {Corpus::CORPUS_UNSPECIFIED}; // sample use of enums defined in the proto file
    
    // using Arena Allocation
    google::protobuf::Arena arena;
    Person* p2 = google::protobuf::Arena::CreateMessage<Person>(&arena); // create a message in this arena, pointer shall not be deleted


    return 0;
}