#!/usr/bin/env python
# coding: utf-8

# In[63]:


import numpy as np
import pandas as pd


# In[64]:


import os


# In[67]:


Outdirectory = 'C:/database-07-mar-2022/course-wise-students-list/'
for directory in os.listdir(Outdirectory):
    directory = Outdirectory + directory + '/'
    for filename in os.listdir(directory):
        i = 0
        s = ""
        while filename[i] != '.':
            s = s + filename[i]
            i = i + 1
        df = pd.read_csv(directory + filename, header = None)
        df['4'] = s
        df.to_csv(directory + filename, header=False, index=False)


# In[68]:


import glob


# In[80]:


def transformer(file_name):
    df=[]
    col='4'
    course_list=os.listdir(parent_dir+file_name)
    for course in course_list:
        temp_df=pd.read_csv(parent_dir+file_name+'/'+str(course), delimiter=',', names=['0','1','2','3'], encoding = 'unicode_escape')
        temp_df[col]= course[:-4]
        df.append(temp_df)
    df=pd.concat(df)
    return df


# In[81]:


df_clws=[]
parent_dir = 'C:/database-07-mar-2022/course-wise-students-list/'
for directories in os.listdir(parent_dir)[1:]:
    df_clws.append(transformer(str(directories)))
df_clws=pd.concat(df_clws)


# In[82]:


df_clws

