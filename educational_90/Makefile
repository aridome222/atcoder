# プロジェクト全体のMakefile

# コンパイラ
CXX = g++

# 共通のコンパイルオプション
CXXFLAGS = -Icpp-dump

# 各サブフォルダのターゲットを指定
SUBDIRS = 001 002

# 各サブフォルダのターゲットをビルド
all: $(SUBDIRS)

# 各サブフォルダのMakefileを呼び出し
$(SUBDIRS):
	$(MAKE) -C $@

# クリーンアップ
clean:
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done
