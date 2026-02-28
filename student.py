class student:
    def __init__(self):
        self.l = {"Name": "", "Roll_no": "", "M1": 0, "M2": 0, "M3": 0, "marks": 0, "grade": ""}

    def input(self):
        self.l["Name"] = input("Enter student name: ")
        self.l["Roll_no"] = input("Enter student roll no: ")
        self.l["M1"] = int(input("Marks in subject 1: "))
        self.l["M2"] = int(input("Marks in subject 2: "))
        self.l["M3"] = int(input("Marks in subject 3: "))

    def calc(self):
        self.l["marks"] = (self.l["M1"] + self.l["M2"] + self.l["M3"]) / 3
        
        if self.l["marks"] >= 90:
            self.l["grade"] = "A"
        elif self.l["marks"] >= 80:
            self.l["grade"] = "B"
        elif self.l["marks"] >= 75:
            self.l["grade"] = "C"
        else:
            self.l["grade"] = "F"

    def output(self):
        print(self.l)


studentob = student()
studentob.input()
studentob.calc()
studentob.output()
