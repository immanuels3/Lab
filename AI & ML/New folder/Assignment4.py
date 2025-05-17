class Node:
    def __init__(self, variable):
        self.variable = variable
        self.parents = []
        self.children = []
        self.probabilities = []

    def addParent(self, parent):
        self.parents.append(parent)

    def addChild(self, child):
        self.children.append(child)

    def setProbabilities(self, probabilities):
        self.probabilities = probabilities

    def getProbability(self, assignments, value):
        # Dummy implementation: Return a fixed probability for now
        return 0.5

    def getParents(self):
        return self.parents

    def getChildren(self):
        return self.children

    def getVariable(self):
        return self.variable

    def getName(self):
        return self.variable


class Edge:
    def __init__(self, source, dest):
        self.source = source
        self.dest = dest


class Sample:
    def __init__(self):
        self.assignments = {}
        self.weight = 1.0

    def setAssignment(self, name, value):
        self.assignments[name] = value

    def getValue(self, name):
        return self.assignments.get(name)

    def setWeight(self, weight):
        self.weight = weight

    def getWeight(self):
        return self.weight