def display(a, b, name, city):
    print(a, b, name, city)

pos_args = (1, 2)
key_args = {"name": "Bob", "city": "NYC"}

display(*pos_args, **key_args) 
