import jieba
import os
from math import log
from operator import itemgetter
import matplotlib.pyplot as plt

class tf_idf:
    def __init__(self):
        self.files = {}     #每个文件的字典，值是归一化后的频率值
        self.corpus = {}    #每个词的频率，未归一化
        self.stop_words = set(())
        self.tf={}
        self.idf={}
        self.tf_idf={}
        content = open('stop_words.txt', 'rb').read().decode('utf-8')
        for line in content.splitlines():   #将stopwords中的单词加入到集合stopwords中
            self.stop_words.add(line)

    def add_file(self, file_name):
        # Load data and cut
        content = open(file_name, 'rb').read() 
        words = jieba.cut(content)

        # Build dictionary
        dictionary = {}
        for w in words:     #统计词出现的次数
            if len(w.strip()) < 2 or w.lower() in self.stop_words:
                continue
            dictionary[w] = dictionary.get(w, 0.0) + 1.0
            self.corpus[w] = self.corpus.get(w, 0.0) + 1.0
 
        # Get term frequency
        total = sum(dictionary.values())
        for k in dictionary:        #将词的出现频率（归一化）
            dictionary[k] /= total

        # Add tf to the corpus
        self.files[file_name] = dictionary

    def get_tf_idf(self,  top_k):  #计算tf*idf,从大到小排序后将值返回
        # Get inverse document frequency
        for w in self.corpus.keys():        #统计出现该词的文件数量
            w_in_f = 1.0
            for f in self.files:
                if w in self.files[f]:
                    w_in_f += 1.0
            #get tf
            self.tf[w]=1+log(self.corpus[w],2)
            #get idf
            self.idf[w]=log(len(self.files) / w_in_f,2)
            # Get tf-idf
            self.tf_idf[w]=self.tf[w]*log(len(self.files) / w_in_f,2)
        # Top-K result of tf-idf
        tags = sorted(self.tf.items(), key=itemgetter(1), reverse=True)
        return tags[:top_k] 


if __name__ == "__main__":      #测试代码
    table = tf_idf()
    tf=[]
    idf=[]
    tfidf=[]
    axis_x=[]
    folder = 'file'
    num_of_files = len([name for name in os.listdir(folder) if os.path.isfile(os.path.join(folder, name))]) + 1

    for x in range(1, num_of_files):
        file_name = 'file' + '/' + str(x).zfill(5) + '.txt'
        table.add_file(file_name)

    for i in range(0,30000):
        axis_x.append(i)
    top_k = 30000
    tf_list=table.get_tf_idf(top_k)

    for li in tf_list:
        tf.append(li[1])
        idf.append(table.idf[li[0]])
        tfidf.append(table.tf_idf[li[0]])


plt.ylabel('tf&idf')
plt.xlabel('word')
plt.scatter(axis_x,tf,c='r',marker="+")
plt.scatter(axis_x,idf,c='y')
plt.show()

plt.ylabel('tf*idf')
plt.xlabel('word')
plt.scatter(axis_x,tfidf)
plt.show()