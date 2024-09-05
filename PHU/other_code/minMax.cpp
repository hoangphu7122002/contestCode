// /* L[k]: Xa nhất về bên trái nhận H[k] là max */
// dq.clear();
// for (int k = 1; k <= N; ++k) {
//     while (dq.size() && H[dq.front()] <= H[k]) dq.pop_front();
//     if (dq.size()) L[k] = dq.front() + 1;
//     else L[k] = k;
//     dq.push_front(k);
// }

// /* R[k]: Xa nhất về bên phải nhận H[k] là max */
// dq.clear();
// for (int k = N; k >= 1; --k) {
//     while (dq.size() && H[dq.front()] <= H[k]) dq.pop_front();
//     if (dq.size()) R[k] = dq.front() - 1;
//     else R[k] = k;
//     dq.push_front(k);
// }

// /* l[k]: Xa nhất về bên trái nhận H[k] là min*/
// dq.clear();
// for (int k = 1; k <= N; ++k) {
//     while (dq.size() && H[dq.front()] >= H[k]) dq.pop_front();
//     if (dq.size()) l[k] = dq.front() + 1;
//     else l[k] = k;
//     dq.push_front(k);
// }

// /* r[k]: Xa nhất về bên phải nhận H[k] là min */
// dq.clear();
// for (int k = N; k >= 1; --k) {
//     while (dq.size() && H[dq.front()] >= H[k]) dq.pop_front();
//     if (dq.size()) r[k] = dq.front() - 1;
//     else r[k] = k;
//     dq.push_front(k);
// }

//basic
// deque <int> dq;

// /* Làm rỗng deque */
// while (dq.size()) dq.pop_front();

// /* Duyệt lần lượt các phần tử từ 1 đến N */
// for (int i = 1; i <= N; ++i) {
//     /* Loại bỏ các phần tử có giá trị lớn hơn hoặc bằng A[i] */
//     while (dq.size() && A[dq.back()] >= A[i]) dq.pop_back();

//     /* Đẩy phần tử i vào queue */
//     dq.push_back(i);

//     /* Nếu phần tử đầu tiên trong deque nằm ngoài khoảng tính
//        thì ta sẽ loại bỏ ra khỏi deque */
//     if (dq.front() + k <= i) dq.pop_front();

//     /* minRange[i] là giá trị nhỏ nhất trong đoạn [i – k + 1 … i] */
//     if (i >= k) minRange[i] = A[dq.front()];
// }