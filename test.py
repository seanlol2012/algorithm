#!/usr/bin/python
# -*- coding: UTF-8 -*-

import random

a = b = c = 1
a,b,c = 1,2,"john"

dict = {}
dict['one'] = "This is one"
dict[2] = "This is two"
 
tinydict = {'name': 'john','code':6734, 'dept': 'sales'}
for a,b in tinydict.items():
    print a,b

#choice(seq)从序列的元素中随机挑选一个元素
#random()随机生成下一个实数，它在[0,1)范围内。

randomnum = random.choice([1,2,3,4,5])
print randomnum

#string.capitalize()
#把字符串的第一个字符大写
#string.count(str, beg=0, end=len(string))
#返回 str 在 string 里面出现的次数，如果 beg 或者 end 指定则返回指定范围内 str 出现的次数
#string.endswith()
#string.find()  string.index()
#string.isalnum  .isalpha .isdecimal .isdigit .islower .isupper
#string.join(seq)

#string.replace(str1, str2,  num=string.count(str1))
#把 string 中的 str1 替换成 str2,如果 num 指定，则替换不超过 num 次.

#string.split(str="", num=string.count(str))
#以 str 为分隔符切片 string，如果 num有指定值，则仅分隔 num 个子字符串

#dict.get(key, default=None)
#返回指定键的值，如果值不在字典中返回default值
#dict.has_key(key)
#如果键在字典dict里返回true，否则返回false
#dict.items()
#以列表返回可遍历的(键, 值) 元组数组
#dict.keys()
#以列表返回一个字典所有的键
#dict.values()
#以列表返回字典中的所有值

now_str = "abcababacabcaaa"
print now_str.count("ab")

print "hello world"

try:
    print "this is try: \n"
    fh = open("testfile","r")
    fh.write("这是测试文件")
except IOError:
    print "Error: 没有找到文件或读取文件失败"
else:
    print "内容写入文件成功"
    fh.close()

class Employee:
    '所有员工的基类'
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1
   
    def displayCount(self):
        print "Total Employee %d" % Employee.empCount
 
    def displayEmployee(self):
        print "Name : ", self.name,  ", Salary: ", self.salary

emp1 = Employee("Zara", 2000)
emp2 = Employee("Manni", 5000)
emp1.displayEmployee()
emp2.displayEmployee()
#hasattr(emp1, 'age')    # 如果存在 'age' 属性返回 True。
#getattr(emp1, 'age')    # 返回 'age' 属性的值
#setattr(emp1, 'age', 8) # 添加属性 'age' 值为 8
#delattr(empl, 'age')    # 删除属性 'age'
print "Total Employee %d" % Employee.empCount

class Parent:        # 定义父类
    parentAttr = 100
    def __init__(self):
        print "调用父类构造函数"

    def parentMethod(self):
        print '调用父类方法'
 
    def setAttr(self, attr):
        Parent.parentAttr = attr

    def getAttr(self):
        print "父类属性 :", Parent.parentAttr

class Child(Parent): # 定义子类
    def __init__(self):
        print "调用子类构造方法"

    def childMethod(self):
        print '调用子类方法 child method'

c = Child()          # 实例化子类
c.childMethod()      # 调用子类的方法
c.parentMethod()     # 调用父类方法
c.setAttr(200)       # 再次调用父类的方法
c.getAttr()          # 再次调用父类的方法

class Aclass:
    countnum = 0
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Aclass.countnum += 1

class Bclass(Aclass):
    def __init__(self):
        print "child init"
    