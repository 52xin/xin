#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Spaceship {
protected:
    string model;
    double speed;
    double energy;
public:
    Spaceship(string m, double s, double e) : model(m), speed(s), energy(e) {}

    string getModel() const { return model; }

    virtual void showStats() {
        cout << "型号：" << model << " | 速度：" << speed << " | 能量：" << energy;
    }

    virtual void action() = 0;

    virtual ~Spaceship() {}
};

class CargoShip : public Spaceship {
private:
    double cargoCapacity;
public:
    CargoShip(string m, double s, double e, double c) : Spaceship(m, s, e), cargoCapacity(c) {}

    void action() override {
        cout << "[运输飞船] " << model << " 正在装载货物" << endl;
    }

    void loadCargo(double cargo) {
        if (cargo <= cargoCapacity) {
            cout << "装载成功！剩余货物容量：" << cargoCapacity - cargo << endl;
        }
        else {
            cout << "装载失败！货物超出最大容量（" << cargoCapacity << "）" << endl;
        }
    }

    void showStats() override {
        Spaceship::showStats();
        cout << " | 货物容量：" << cargoCapacity << endl;
    }
};

class BattleShip : public Spaceship {
private:
    double weaponPower;
    const double ENERGY_COST = 10.0;
public:
    BattleShip(string m, double s, double e, double p) : Spaceship(m, s, e), weaponPower(p) {}

    void action() override {
        cout << "[战斗飞船] " << model << " 即将发射激光" << endl;
    }

    void fireLaser() {
        if (energy >= ENERGY_COST) {
            energy -= ENERGY_COST;
            cout << "激光发射成功！剩余能量：" << energy << endl;
        }
        else {
            cout << "能量不足（当前：" << energy << "），无法发射激光" << endl;
        }
    }

    void showStats() override {
        Spaceship::showStats();
        cout << " | 武器威力：" << weaponPower << endl;
    }
};

class ExplorerShip : public Spaceship {
private:
    double scanRange;
    const double ENERGY_COST = 8.0;
public:
    ExplorerShip(string m, double s, double e, double r) : Spaceship(m, s, e), scanRange(r) {}

    void action() override {
        cout << "[探索飞船] " << model << " 正在扫描星球" << endl;
    }

    void scanPlanet() {
        if (energy >= ENERGY_COST) {
            energy -= ENERGY_COST;
            cout << "星球扫描完成！剩余能量：" << energy << endl;
        }
        else {
            cout << "能量不足（当前：" << energy << "），无法扫描星球" << endl;
        }
    }

    void showStats() override {
        Spaceship::showStats();
        cout << " | 扫描范围：" << scanRange << "光年" << endl;
    }
};

class SpaceshipFleet {
private:
    vector<Spaceship*> fleet;
public:

    bool empty()const
    {
        return fleet.empty();
    }
    void addShip(Spaceship* ship) {
        fleet.push_back(ship);
        cout << "飞船【" << ship->getModel() << "】已添加到飞船库" << endl;
    }

    void showAllShips() {
        if (fleet.empty()) {
            cout << "飞船库为空！" << endl;
            return;
        }

        int cargoCnt = 0, battleCnt = 0, explorerCnt = 0;
        for (auto ship : fleet) {
            if (dynamic_cast<CargoShip*>(ship)) cargoCnt++;
            else if (dynamic_cast<BattleShip*>(ship)) battleCnt++;
            else if (dynamic_cast<ExplorerShip*>(ship)) explorerCnt++;
        }

        cout << "\n===== 飞船库统计 =====" << endl;
        cout << "运输飞船：" << cargoCnt << "艘 | 战斗飞船：" << battleCnt << "艘 | 探索飞船：" << explorerCnt << "艘" << endl;

        cout << "\n===== 飞船详情 =====" << endl;
        for (size_t i = 0; i < fleet.size(); i++) {
            cout << i + 1 << ". ";
            fleet[i]->showStats();
        }
    }

    void rentShip(int idx) {
        if (idx < 1 || idx > fleet.size()) {
            cout << "飞船编号无效！" << endl;
            return;
        }

        Spaceship* ship = fleet[idx - 1];
        cout << "\n===== 租赁飞船【" << ship->getModel() << "】=====" << endl;
        ship->action();

        if (CargoShip* cargo = dynamic_cast<CargoShip*>(ship)) {
            double cargoNum;
            cout << "请输入装载货物数量：";
            cin >> cargoNum;
            cargo->loadCargo(cargoNum);
        }
        else if (BattleShip* battle = dynamic_cast<BattleShip*>(ship)) {
            battle->fireLaser();
        }
        else if (ExplorerShip* explorer = dynamic_cast<ExplorerShip*>(ship)) {
            explorer->scanPlanet();
        }
    }

    void searchShip(const string& keyWord) {
        cout << "\n===== 搜索关键词：" << keyWord << " =====" << endl;
        bool found = false;
        for (size_t i = 0; i < fleet.size(); i++) {
            if (fleet[i]->getModel().find(keyWord) != string::npos) {
                cout << i + 1 << ". ";
                fleet[i]->showStats();
                found = true;
            }
        }
        if (!found) {
            cout << "未找到匹配的飞船！" << endl;
        }
    }

    ~SpaceshipFleet() {
        for (auto ship : fleet) delete ship;
    }
};

void showMenu() {
    cout << "\n===== 星际飞船管理系统 =====" << endl;
    cout << "1. 增加飞船" << endl;
    cout << "2. 租赁飞船" << endl;
    cout << "3. 查看所有飞船" << endl;
    cout << "4. 搜索飞船" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请选择操作：";
}

void addShipMenu(SpaceshipFleet& fleet) {
    int type;
    cout << "\n===== 选择飞船类型 =====" << endl;
    cout << "1. 运输飞船" << endl;
    cout << "2. 战斗飞船" << endl;
    cout << "3. 探索飞船" << endl;
    cout << "请选择类型：";
    cin >> type;

    string model;
    double speed, energy;
    cout << "请输入飞船型号：";
    cin >> model;
    cout << "请输入飞船速度：";
    cin >> speed;
    cout << "请输入飞船能量：";
    cin >> energy;

    switch (type) {
    case 1: {
        double cargoCapacity;
        cout << "请输入货物容量：";
        cin >> cargoCapacity;
        fleet.addShip(new CargoShip(model, speed, energy, cargoCapacity));
        break;
    }
    case 2: {
        double weaponPower;
        cout << "请输入武器威力：";
        cin >> weaponPower;
        fleet.addShip(new BattleShip(model, speed, energy, weaponPower));
        break;
    }
    case 3: {
        double scanRange;
        cout << "请输入扫描范围（光年）：";
        cin >> scanRange;
        fleet.addShip(new ExplorerShip(model, speed, energy, scanRange));
        break;
    }
    default:
        cout << "类型选择错误！" << endl;
    }

   
}

int main() {
    SpaceshipFleet fleet;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addShipMenu(fleet);
            break;
        case 2: {
            if (fleet.empty()) {
                cout << "飞船库为空，无法租赁！" << endl;
                break;
            }
            int idx;
            cout << "请输入要租赁的飞船编号：";
            cin >> idx;
            fleet.rentShip(idx);
            break;
        }
        case 3:
            fleet.showAllShips();
            break;
        case 4: {
            if (fleet.empty()) {
                cout << "飞船库为空，无法搜索！" << endl;
                break;
            }
            string keyWord;
            cout << "请输入搜索关键词（飞船型号）：";
            cin >> keyWord;
            fleet.searchShip(keyWord);
            break;
        }
        case 0:
            cout << "退出系统成功！" << endl;
            return 0;
        default:
            cout << "操作选择错误，请重新输入！" << endl;
        }
    }
}