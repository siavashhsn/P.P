from collections import defaultdict

#################################### graph class to hold graphs and check if it has cycle or not

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


#################################### sersializable function

def serializable():
	g = Graph(len(tr_count))
	for i in range(len(allTrn)-1):
		if [x for x in ['W', 'R'] if x in allTrn[i]]:
			for j in range(i+1, len(allTrn)):
				if [x for x in ['W', 'R'] if x in allTrn[j]]:
					if allTrn[i][1:3] != allTrn[j][1:3]:
						if ("W" in allTrn[i]) or ("W" in allTrn[j]):
							if (allTrn[i][4] == allTrn[j][4]):
								g.addEdge(tr_count[allTrn[i][1:3]], tr_count[allTrn[j][1:3]])

	if g.isCyclic() == 1:
		return False
	else:
		return True

#################################### recoverable function

def recoverable():
	r_is_exist = False
	r_tr_num   = False
	is_commited = False
	for i in range(len(allTrn)-2):
		if "W" in allTrn[i]:	
			for j in range(i+1, len(allTrn)):
				if ("R" in allTrn[j]) and (allTrn[i][1:3] != allTrn[j][1:3]) and (allTrn[i][4] == allTrn[j][4]):
					r_tr_num = allTrn[j][1:3]
					for k in range(i+1, len(allTrn)):
						if ("C" in allTrn[k]) and (allTrn[k][1:3] == allTrn[j][1:3]):
							return False
						elif ("C" in allTrn[k]) and (allTrn[k][1:3] == allTrn[i][1:3]):
							is_commited = True
							break
					if is_commited == True:
						break
	return True

#################################### casscadeless function

def casscadeless():
	r_is_exist = False
	r_tr_num   = False
	is_commited = False

	commit_index = []
	read_index   = []

	for i in range(len(allTrn)-2):
		if "W" in allTrn[i]:	
			for j in range(i+1, len(allTrn)):
				if ("C" in allTrn[j]): # and (allTrn[i][1:3] == allTrn[j][1:3]):
					commit_index.append(j)
				if ("R" in allTrn[j]) and (allTrn[j][1:3] != allTrn[i][1:3]) and (allTrn[i][4] == allTrn[j][4]):
					read_index.append(j)
					
			if len(commit_index) and len(read_index):
				if min(commit_index) > min(read_index):
					return False

	return True

#################################### main get instructions line by line

if __name__ == "__main__":
	n = raw_input()
	for i in range(int(n)):
		a = raw_input()
		allTrn.append(a)
		if a[1:3] not in tr_count:
			tr_count[a[1:3]] = counter
			counter += 1
	
	if serializable() == True:
		print "YES"
	else:
		print "NO"
	
	if recoverable() == True:
		print "YES"
	else:
		print "NO"

	if casscadeless() == True:
		print "YES"
	else:
		print "NO"


#################################### calling seri... recov... cassc... functions


