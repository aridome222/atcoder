# サブフォルダのMakefile

# プロジェクトルートから継承
CXX = g++
CXXFLAGS = -I../cpp-dump

# ソースファイル
SOURCES = a2.cpp

# ターゲット実行ファイル
TARGET = a2

# コンパイルルール
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# クリーンアップ
clean:
	rm -f $(TARGET)
