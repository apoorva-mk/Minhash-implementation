
class openadd:
	def __init__(self,type):
		self.table=[ None for i in range(8)]
		self.size=8
		self.load=0
		self.type=type

	def linearadd(self,val):
		key=val%self.size
		while self.table[key]!=None:
			key=(key+1)%self.size
		self.table[key]=val
	def linearsearch(self,val):
		f=1
		key=val%self.size
		i=0
		while self.table[key]!=val:
			key=(key+1)%self.size
			i=i+1
			if i==self.size:
				f=0
				break
		return f
	def quadadd(self,val):
		i=1
		key=val%self.size
		while self.table[key]!=None:
			key=(key+i*i)%self.size
			i=i+1
		self.table[key]=val
	def quadsearch(self,val):
		f=1
		key=val%self.size
		i=0
		j=1
		while self.table[key]!=val:
			print(key)
			key=(key+j*j)%self.size
			j=j+1
			i=i+1
			if i==self.size+1:
				f=0
				break
		return f
	def doubleadd(self,val):
		probe=val%self.size
		offset=val%7
		i=0
		if offset%2==0:
			offset+=1
		while self.table[probe]!=None:
			probe=(probe+offset)%self.size
			i=i+1
		self.table[probe]=val
	def doublesearch(self,val):
		f=1
		probe=val%self.size
		offset=val%7
		if offset%2==0:
			offset+=1
		i=0
		while self.table[probe]!=val:
			probe=(probe+offset)%self.size
			i=i+1
			if i==self.size:
				f=0
				break
		return f
	def resize(self):
		oldtable=self.table
		self.table=[None for i in range(self.size*2)]
		self.size=self.size*2
		for i in range(int(self.size/2)):
			if oldtable[i]==None:
				continue
			self.add(oldtable[i])

			
	def add(self,val):
		if self.type==1:
			self.linearadd(val)
			self.load+=1
		elif self.type==2:
			self.quadadd(val)
			self.load+=1
		elif self.type==3:
			self.doubleadd(val)
			self.load+=1
		else:
			return
		if self.load/self.size>=0.75:
			self.resize()
			
	def search(self,val):
		if self.type==1:
			return self.linearsearch(val)
			
		elif self.type==2:
			return self.quadsearch(val)
			
		elif self.type==3:
			return self.doublesearch(val)
			
		else:
			return
	def printtable(self):
		for i in range(self.size):
			if self.table[i]!=None:
				print(self.table[i])

def main():
	hashtable=openadd(2)
	hashtable.add(5)
	hashtable.add(13)
	hashtable.add(6)
	hashtable.add(7)
	hashtable.add(9)
	hashtable.add(34)
	hashtable.add(23)
	hashtable.add(12)
	hashtable.add(90)
	print(hashtable.search(13))
	#hashtable.printtable()


if __name__ == '__main__':
	main()



