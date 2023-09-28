#include <vector>
#include <bits/stdc++.h>
#include "client_generated.h"
using namespace client_space;
int main() {
    flatbuffers::FlatBufferBuilder builder;
    auto alice = CreatePerson(builder, builder.CreateString("Alice"), 25, 55.0f, Gender_Female);
    auto bob = CreatePerson(builder, builder.CreateString("Bob"), 30, 70.0f, Gender_Male);
    std::vector <std::string> group1_names = {"Alice", "Bob", "Charlie"};
    std::vector <flatbuffers::Offset<flatbuffers::String>> group1_names_offsets;
    for (const auto &name: group1_names) {
        group1_names_offsets.push_back(builder.CreateString(name));
    }
    auto group1 = CreateGroup(builder, builder.CreateString("Group 2"), 32.0f, 75.0f,
                              builder.CreateVector(group1_names_offsets));
    auto client1 = CreateClient(
            builder,
            PersonOrGroup_Person,
            alice.Union()
    );
    auto client2 = CreateClient(
            builder,
            PersonOrGroup_Person,
            bob.Union()
    );
    auto client3 = CreateClient(
            builder,
            PersonOrGroup_Group,
            group1.Union()
    );
    std::vector<flatbuffers::Offset<Client>> clients;
    clients.push_back(client1);
    clients.push_back(client2);
    clients.push_back(client3);
    auto data = CreateData(builder, builder.CreateVector(clients));
    builder.Finish(data);
    uint8_t *buf = builder.GetBufferPointer();
    int size = builder.GetSize();
    std::ofstream ofile("bytes_client.bin", std::ios::binary);
    ofile.write((char *)buf, size);
    ofile.close();
    std::cout << "Bytes Have been written succesfully";
}

