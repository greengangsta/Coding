class Person:
    def __init__(self,name):
        self.name = name

class Employee(Person):
    def __init__(self,job):
        self.job = job

class Manager(Employee):
    def __init__(self,dep,name,job):
        self.dep = dep
        self.name = name
        self.job = job
        
mg = Manager('IT','Shikhar','Engineer')
print(mg.dep)
print(mg.name)
print(mg.job)