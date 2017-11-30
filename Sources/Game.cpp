#include "Game.hpp"


<<<<<<< HEAD
=======
<<<<<<< HEAD
// TODO: 砲台の位置を画面左に、ターゲットの位置を画面右に移動させる。(A)
// TODO: 雲の位置を左から右に動かす。見えなくなったら左端に戻す。(B)
// TODO: 砲台を青い壁に沿って上下に動かす。(C) //kurotsu
// TODO: 弾のスピードを速くし、弾が画面右端を通り越したら再度発射可能にする。(D)
// TODO: スコアのサイズを大きくする。(E)
// TODO: スコアを100点ずつ加算するようにし、5桁の表示に変える。(F)
// TODO: PlayBGM()関数を使って、BGMを再生する。(G) //kurotsu
// TODO: PlaySE()関数を使って、弾の発射時とターゲットに当たった時にSEを再生する。(H)
=======
>>>>>>> bf618ab065e4e358ef330aa1be49b3c061d22d22
// TODO: 砲台の位置を画面左に、ターゲットの位置を画面右に移動させる。(A)(実装:HW16A097 新甚 礁太)
// TODO: 雲の位置を左から右に動かす。見えなくなったら左端に戻す。(B)(実装:HW16A209 谷津 峻哉)
// TODO: 砲台を青い壁に沿って上下に動かす。(C)(実装:HW16A072 黒津 勇斗)
// TODO: 弾のスピードを速くし、弾が画面右端を通り越したら再度発射可能にする。(D)(実装:HW16A207 森本 義基)
// TODO: スコアのサイズを大きくする。(E)(実装:HW16A097 新甚 礁太)
// TODO: スコアを100点ずつ加算するようにし、5桁の表示に変える。(F)(実装:HW16A209 谷津 峻哉)
// TODO: PlayBGM()関数を使って、BGMを再生する。(G)(実装:HW16A072 黒津 勇斗)
// TODO: PlaySE()関数を使って、弾の発射時とターゲットに当たった時にSEを再生する。(H)(実装:HW16A207 森本 義基)
<<<<<<< HEAD
=======
>>>>>>> 9b816627f8d442cef882bd92fbdeb1242d2d521f
>>>>>>> bf618ab065e4e358ef330aa1be49b3c061d22d22


Vector2 cloudPos;       //!< 雲の位置
Vector2 cannonPos;      //!< 砲台の位置
Vector2 bulletPos;      //!< 弾の位置
Rect    targetRect;     //!< ターゲットの矩形
int     score;          //!< スコア
int ca = 0;  //追加文

// ゲーム開始時に呼ばれる関数です。
void Start()
{
    cloudPos = Vector2(-320, 100);
    cannonPos = Vector2(-80, -150);
    targetRect = Rect(80, -140, 40, 40);
    bulletPos.x = -999;
    score = 0;
    
   
    PlaySound("bgm_maoudamashii_8bit07.mp3"); //追加文
}

// 1/60秒ごとに呼ばれる関数です。モデルの更新と画面の描画を行います。
void Update()
{
<<<<<<< HEAD
    //雲の位置を左から右に動かす。見えなくなったら左端に戻す
    if (cloudPos.x > -550) {
        cloudPos.x += 60 * Time::deltaTime;
        if (cloudPos.x > 340) {
            cloudPos.x = -540;
        }
    }
=======
>>>>>>> bf618ab065e4e358ef330aa1be49b3c061d22d22
    
    // 弾の発射
    if (bulletPos.x <= -999 && Input::GetKeyDown(KeyMask::Space)) {
        bulletPos = cannonPos + Vector2(50, 10);
    }

    // 弾の移動
    if (bulletPos.x > -999) {
        bulletPos.x += 10 * Time::deltaTime;
        

        // ターゲットと弾の当たり判定
        Rect bulletRect(bulletPos, Vector2(32, 20));
        if (targetRect.Overlaps(bulletRect)) {
            score += 100;         // スコアの加算
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
        }
    }
    
    if (cannonPos.y < -149){
        ca=0;
    }
    if (cannonPos.y > -69){
        ca=1;
    }
    if (ca == 0){
        cannonPos.y += 50 * Time::deltaTime;
    } else if (ca == 1){
        cannonPos.y -= 50 * Time::deltaTime;
    } // 56~66 追加文

    // 背景の描画
    Clear(Color::cyan);
    FillRect(Rect(-320, -240, 640, 100), Color::green);

    // 雲の描画
    DrawImage("cloud1.png", cloudPos);

    // 弾の描画
    if (bulletPos.x > -999) {
        DrawImage("bullet.png", bulletPos);
    }

    // 砲台の描画
    FillRect(Rect(cannonPos.x-10, -140, 20, 100), Color::blue);
    DrawImage("cannon.png", cannonPos);

    // ターゲットの描画
    FillRect(targetRect, Color::red);

    // スコアの描画
    SetFont("nicoca_v1.ttf", 20.0f);
    DrawText(FormatString("%05d", score), Vector2(-319, 199), Color::black);
    DrawText(FormatString("%05d", score), Vector2(-320, 200), Color::white);
}

