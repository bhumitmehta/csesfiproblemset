class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

def solve():
    t = int(input())
    for _ in range(t):
        n, m, p = map(int, input().split())
        need_internet = list(map(int, input().split()))
        
        edges = []
        for _ in range(m):
            u, v, w = map(int, input().split())
            edges.append((w, u-1, v-1))
        
        # Sort edges by latency (Kruskal's approach)
        edges.sort()
        
        # Prepare DSU for the Minimum Spanning Tree
        dsu = DSU(n)
        mst_edges = []
        
        for w, u, v in edges:
            if dsu.find(u) != dsu.find(v):
                dsu.union(u, v)
                mst_edges.append((w, u, v))
        
        # Compute latencies for each k from 1 to n
        result = [0] * n
        # Code for calculating minimum latencies goes here
        
        print(" ".join(map(str, result)))

