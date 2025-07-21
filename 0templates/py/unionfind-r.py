class UF:
    def __init__(self, n):
        self.par = list(range(n))
        self.rank = [0] * n
        
    def find(self, query):
        if query == self.par[query]:
            return query
        u_par = self.find(self.par[query])
        self.par[query] = u_par
        return u_par

    def union(self, node1, node2):
        par1, par2 = self.find(node1), self.find(node2)
        if par1 == par2:
            return False

        if self.rank[par1] > self.rank[par2]:
            self.par[par2] = self.par[par1]
        elif self.rank[par2] > self.rank[par1]:
            self.par[par1] = self.par[par2]
        else:
            self.par[par1] = self.par[par2]
            self.rank[par2] += 1

        return True