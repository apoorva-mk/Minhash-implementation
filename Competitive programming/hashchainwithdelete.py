class ListNode:
	def __init__(self,val=None,nxt=None,pr=None):
		self.val=val
		self.next=nxt
		self.prev=pr
class hashtable:
	def __init__(self,size):
		self.Table= [None for i in range(size)]
		self.size=size
	def getkey(self,el):
		num=0
		for i in el:
			num+=ord(i)
		return num%self.size
	def insert(self,el):
		value=self.getkey(el)
		#print(value)
		if self.Table[value]==None:
			node=ListNode(el,None,None)
			self.Table[value]=node
		else:

			node=ListNode(el,self.Table[value],None)
			node.next.prev=node
			self.Table[value]=node

	def delete(self,val):
		g=self.search(val)
		if g==0:
			return
		else:
			
			if g.prev==None and g.next==None:
				self.Table[self.getkey(val)]=None
			if g.next!=None:
				g.next.prev=g.prev

			if g.prev!=None:
				g.prev.next=g.next
			else:
				self.Table[self.getkey(val)]=g.prev


	def search(self,el):
		val=self.getkey(el)
		if self.Table[val]==None:
			return 0
		else:
			f=0
			temp=self.Table[val]
			while temp!=None:
				if temp.val==el:
					f=1
					break
				temp=temp.next
			if f==1:
				return temp
			return f


	def keys(self):
		for i in range(self.size):
				if self.Table[i]==	None:
					continue
				else:
					temp=self.Table[i]
					while(temp!=None):
						print(temp.val)
						temp=temp.next

def main():
	print("Enter size of the hash table")
	sz=int(input())
	print("Creating a hash table :")
	ht= hashtable(sz)
	print("Enter number of elements you want to enter :")
	ele=int(input())
	for i in range(ele):
		inp=input()
		ht.insert(inp)
	print("Printing table :")
	ht.keys()
	print("Enter value you want to delete :")
	val=(input())
	ht.delete(val)
	print("Printing table :")
	ht.keys()
	print("Enter key you want to search :")
	key=input()
	if ht.search(key)==0 :
		print("Not Found")
	else:
		print("Found")

if __name__ == '__main__':
    main()




