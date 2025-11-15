# Makefile

CXX      := g++-15
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Wpedantic
TARGET   := a.out

.PHONY: clean

# ビルドターゲット
# 例: make build b → b.cpp をコンパイル
build:
ifeq ($(words $(MAKECMDGOALS)),1)
	$(error ファイルを指定してください: make build <a|b|c|d>)
endif
	$(CXX) $(CXXFLAGS) $(word 2,$(MAKECMDGOALS)).cpp -o $(TARGET)

# 実行
run:
	./$(TARGET)

# クリーン
clean:
	rm -f $(TARGET)
