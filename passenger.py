class passenger:
    def __init__(self,state="",occupancy=0,color=""):
        self.state=state
        self.occupancy=occupancy
        self.color=color
    def car(self):
        self.state=input("Enter car state on or off")
        self.occpancy=int(input("Enter car occupancy"))
        self.color=input("Enter color of car")
        print(f"The car has following attributes state-{self.state}  occupance {self.occupancy}  color {self.color}")
    def bike(self):
        self.state=input("Enter bike state on or off")
        self.occupancy=int(input("Enter bike occupancy"))
        self.color=input("Enter color of bike")
        print(f"The car has following attributes state-{self.state}  occupance {self.occupancy}  color {self.color}")
    def Truck(self):
        self.state=input("Enter Truck state on or off")
        self.occupancy=int(input("Enter Truck occupancy"))
        self.color=input("Enter color of Truck")
        print(f"The car has following attributes state-{self.state}  occupance {self.occupancy}  color {self.color}")
passengerob=passenger()
passengerob.car()