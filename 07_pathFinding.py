# TRANSPORTATION problem


class TransportationProblem:

    """
    street with blocks numbered from1 to N
    Walking from s to s+1 takes 1 minute
    Taking a magic tram s to 2s takes 2 minutes.
    How to travel from 1 to n in the least time?
    """

    def __init__(self, N):
        self.N = N

    def startState(self):
        return 1

    def isEnd(self, state):
        return state == self.N

    def succAndCost(self, state):
        # actions
        result = []
        if state + 1 <= self.N:
            result.append(("walk", state + 1, 1))
        if state * 2 <= self.N:
            result.append(("tram", state * 2, 2))
        return result



def backtrackingSearch(problem):










problem = TransportationProblem(10)

print(problem.succAndCost(9))
