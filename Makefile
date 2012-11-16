TARGET1 = surf  # コンパイルしたいプログラム名
#TARGET2 = bmpout 
#TARGET3 = svmdetect
SOURCE1 = surf.cpp 
#SOURCE2 = bmpout.cpp
#SOURCE3 = svmdetect.cpp
#OBJS = hoge.o hige.o # プログラムのソースコードの拡張子を.oにしたやつ

CXX = g++      # 好きなコンパイラ
CXXFLAGS = -Wall -O2 # この辺は適当

# OpenCV のライブラリを指定
OPENCVINC = `pkg-config --cflags opencv`
OPENCVLIB = `pkg-config --libs opencv`
#
# $(TARGET):$(OBJS)
# 	$(CXX) -o $@ $(OBJS) $(OPENCVLIB)
#
# 	.cpp.o:
# 		$(CXX) -c -o $@ $< $(OBJINCS)
$(TARGET1):$(SOURCE1)
	$(CXX) $(OPENCVINC)$(OPENCVLIB) -o $(TARGET1) $(SOURCE1) 
#$(TARGET2):$(SOURCE2) 
	#$(CXX) $(OPENCVINC)$(OPENCVLIB) -o $(TARGET2) $(SOURCE2) 
#$(TARGET3):$(SOURCE3)
	#$(CXX) $(OPENCVINC)$(OPENCVLIB) -o $(TARGET3) $(SOURCE3) 
