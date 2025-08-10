#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Command {
    string name;
    int numOptions;
    vector<string> options;
};

struct Analyzer {
    map<string, Command> commands;
    map<string, int> optionCounts;

    void addCommand(const string& name, const vector<string>& options) {
        Command cmd = {name, options.size(), options};
        commands[name] = cmd;
        for (const auto& opt : options) {
            ++optionCounts[opt];
        }
    }

    void analyze() {
        for (const auto& cmd : commands) {
            cout << "Command: " << cmd.first << endl;
            cout << "  Options: ";
            for (const auto& opt : cmd.second.options) {
                cout << opt << " ";
            }
            cout << endl;
        }
        cout << "Option Counts:" << endl;
        for (const auto& opt : optionCounts) {
            cout << "  " << opt.first << ": " << opt.second << endl;
        }
    }
};

int main() {
    Analyzer analyzer;
    analyzer.addCommand("create", {"-n", "--name", "-d", "--description"});
    analyzer.addCommand("list", {"-a", "--all", "-f", "--filter"});
    analyzer.addCommand("delete", {"-n", "--name", "--force"});
    analyzer.analyze();
    return 0;
}