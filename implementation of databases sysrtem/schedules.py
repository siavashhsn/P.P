from collections import defaultdict


class Graph():
	def __init__(self,node):
		self.graph = defaultdict(list)
		self.V = node

	def addEdge(self,u,v):
		self.graph[u].append(v)

	def isCyclicUtil(self, v, visited, recStack):

		# Mark current node as visited and 
		# adds to recursion stack
		visited[v] = True
		recStack[v] = True

		# Recur for all neighbours
		# if any neighbour is visited and in 
		# recStack then graph is cyclic
		for neighbour in self.graph[v]:
			if visited[neighbour] == False:
				if self.isCyclicUtil(neighbour, visited, recStack) == True:
					return True
			elif recStack[neighbour] == True:
				return True

		# The node needs to be poped from 
		# recursion stack before function ends
		recStack[v] = False
		return False

	# Returns true if graph is cyclic else false
	def isCyclic(self):
		visited = [False] * self.V
		recStack = [False] * self.V
		for node in range(self.V):
			if visited[node] == False:
				if self.isCyclicUtil(node,visited,recStack) == True:
					return True
		return False


allTrn   = []
tr_count = {}
counter = 0

n = raw_input()
for i in range(int(n)):
	a = raw_input()
	allTrn.append(a)
	if a[1:3] not in tr_count:
		tr_count[a[1:3]] = counter
		counter += 1

g = Graph(len(tr_count))

for i in range(1, len(allTrn)):
	if "W" or "R" in allTrn[i] and allTrn[i-1]:
		if len(allTrn[i])==5 and len(allTrn[i-1])==5: 
			if (allTrn[i][1:3] != allTrn[i-1][1:3]) and (allTrn[i][4] == allTrn[i-1][4]):
				if "W" in allTrn[i][3] or allTrn[i-1][3]:
					g.addEdge(tr_count[allTrn[i-1][1:3]], tr_count[allTrn[i][1:3]])

if g.isCyclic() == 1:
	print "NO"
else:
	print "YES"

