import flatbuffers
from client_space import Data, Group, Person, Gender, PersonOrGroup

def print_person(person):
    print("Name:", person.Name().decode('utf-8'))
    print("Age:", person.Age())
    print("Weight:", person.Weight())
    gender = "Male" if person.Gender() == Gender.Gender.Male else "Female"
    print("Gender:", gender)

def print_group(group):
    print("Group Name:", group.GroupName().decode('utf-8'))
    print("Average Age:", group.AvgAge())
    print("Average Weight:", group.AvgWeight())
    length = group.NamesLength()
    print("Names:")
    for i in range(length):
      print(group.Names(i).decode('utf-8'),end=" ")

def main():
    with open("bytes_client.bin", "rb") as file:
        data = file.read()

    buf = bytearray(data)
    client = Data.Data.GetRootAsData(buf, 0)
    for i in range(client.DataLength()):
        client_type = client.Data(i).TypeType()
        if client_type == PersonOrGroup.PersonOrGroup.Person:
            person = Person.Person()
            person.Init(client.Data(i).Type().Bytes, client.Data(i).Type().Pos)
            print_person(person)
        elif client_type == PersonOrGroup.PersonOrGroup.Group:
            group = Group.Group()
            group.Init(client.Data(i).Type().Bytes, client.Data(i).Type().Pos)
            print_group(group)
        else:
            print("Unknown client type")

if _name_ == "_main_":
    main()
 isse save krlo ek baar
