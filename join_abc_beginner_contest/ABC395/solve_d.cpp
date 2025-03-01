#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    using namespace std;

    unsigned N;
    cin >> N;

    // box_to_label : i 番目の巣に入っているラベル鳩の番号
    // label_to_box : i 番目のラベル鳩が入っている巣の番号(ラベル鳩 = 本来の巣iのラベル)
    // pigeon_to_box : i 番目の鳩が入っている巣の番号
    vector<unsigned> box_to_label(N), label_to_box(N), pigeon_to_box(N);
    iota(begin(box_to_label), end(box_to_label), 0U);
    iota(begin(label_to_box), end(label_to_box), 0U);
    iota(begin(pigeon_to_box), end(pigeon_to_box), 0U);

    unsigned Q;
    cin >> Q;
    for (unsigned q{}; q < Q; ++q)
    {
        unsigned type;
        cin >> type;
        if (type == 1)
        {
            unsigned pigeon, to;
            cin >> pigeon >> to;
            // 鳩 → 巣の情報を更新（例：鳩1がラベル30がある巣に移動。ラベル30は巣30が最終的に移動した場所を指す）
            pigeon_to_box[pigeon - 1] = label_to_box[to - 1];
        }
        else if (type == 2)
        {
            unsigned label0, label1;
            cin >> label0 >> label1;
            // ラベル鳩 → 巣の情報を更新
            swap(label_to_box[label0 - 1], label_to_box[label1 - 1]);
            // 巣 → ラベル鳩の情報を更新
            swap(box_to_label[label_to_box[label0 - 1]], box_to_label[label_to_box[label1 - 1]]);
        }
        else
        {
            unsigned pigeon;
            cin >> pigeon;
            cout << box_to_label[pigeon_to_box[pigeon - 1]] + 1 << '\n';
        }
    }
    // cout << flush;
    return 0;
}
