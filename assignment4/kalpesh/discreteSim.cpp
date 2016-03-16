#include <iostream>
#include <vector>
#include <unordered_map>
#include "MinMaxHeap.hpp"
using namespace std;
class Microbe {
	private:
		int identity;
		int strength;
		int n;
		bool infected;
		bool dead;
	public:
		Microbe() {
			identity = 0;
			strength = 0;
			n = 0;
			infected = true;
			dead = true;
		}

		Microbe(int id, int str) {
			identity = id;
			strength = str;
			n = (((identity + strength) * 29) % 37) + 7;
			infected = false;
			dead = false;
		}

		int getIdentity() {
			return identity;
		}

		int getStrength() {
			return strength;
		}

		int getN() {
			return n;
		}

		void reduceStrength() {
			strength = strength - 1;
		}

		void infect() {
			infected = true;
		}

		void kill() {
			dead = true;
		}

		bool isInfected() {
			return infected;
		}

		bool isDead() {
			return dead;
		}
};

class Event {
	private:
		int step;
		char type; // death, infection, cell division
		int subject;
	public:
		Event() {
			step = -1;
			type = 'd';
			subject = 0;
		}

		Event(int s, int t, int sub) {
			step = s;
			type = t;
			subject = sub;
		}

		bool operator <(const Event& e) {
			if (step < e.step) return true;
			else if (step > e.step) return false;
			else {
				// Both have the same timestep, check type of event
				if (type == 'd' && e.type == 'd') {
					if (subject <= e.subject) return true;
					else return false;
				} else if (type == 'd' && e.type != 'd') {
					return true;
				} else if (type == 'i' && e.type == 'd') {
					return false;
				} else if (type == 'i' && e.type == 'i') {
					if (subject <= e.subject) return true;
					else return false;
				} else if (type == 'i' && e.type == 'c') {
					return true;
				} else if (type == 'c' && e.type != 'c') {
					return false;
				} else if (type == 'c' && e.type == 'c') {
					if (subject <= e.subject) return true;
					else return false;
				} else return true;
			}
		}

		int getStep() {
			return step;
		}

		char getType() {
			return type;
		}

		int getSubject() {
			return subject;
		}
};

int main() {
	int M, N, T;
	cin >> N;
	unordered_map<int, Microbe*> culture;
	MinMaxHeap<Event> sim;
	for (int i = 0; i < N; i++) {
		int str;
		cin >> str;
		Microbe* m1 = new Microbe(i, str);
		culture.insert(pair<int, Microbe*>(i, m1));
		// Create events for first cell division.
		// Subsequent divisions scheduled after the first division takes place.
		Event *e1 = new Event(m1->getN(), 'c', i);
		sim.insert(*e1);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int mic, step;
		cin >> mic >> step;
		Event *e1 = new Event(step, 'i', mic);
		sim.insert(*e1);
	}
	int timestep = 0, global_identity = N, population = N;
	cin >> T;
	while(timestep <= T && timestep >= 0) { // timestep >= 0 ensures events aren't over
		// Change data structure values, update output
		Event nextEvent = sim.getMin();
		while(timestep == nextEvent.getStep()) {
			Microbe* subject = culture[nextEvent.getSubject()];
			if (nextEvent.getType() == 'c') {
				// Always check whether microbe is infected / dead!
				if (!(subject->isInfected() || subject->isDead())) {
					Microbe* m1 = new Microbe(global_identity, subject->getStrength());
					culture.insert(pair<int, Microbe*>(global_identity, m1));
					cout << "b " << global_identity << " " << timestep << endl;
					global_identity++;
					population++;
					subject->reduceStrength();
					// Schedule events for m1's division and subject's next division / death
					Event *e1 = new Event(timestep + m1->getN(), 'c', m1->getIdentity());
					sim.insert(*e1);
					if (subject->getStrength() == 0) {
						// Last division done, schedule death
						Event *e2 = new Event(timestep + subject->getN(), 'd', subject->getIdentity());
						sim.insert(*e2);
					} else {
						// Prepare for next division
						Event *e2 = new Event(timestep + subject->getN(), 'c', subject->getIdentity());
						sim.insert(*e2);
					}

				}
			} else if (nextEvent.getType() == 'i') {
				if (!subject->isDead()) {
					subject->infect();
					// Schedule subject's death
					Event *e1 = new Event(timestep + subject->getStrength(), 'd', subject->getIdentity());
					sim.insert(*e1);
				}
			} else if (nextEvent.getType() == 'd') {
				subject->kill();
				cout << "d " << subject->getIdentity() << " " << timestep << endl;
				population--;
			}
			sim.deleteMin();
			nextEvent = sim.getMin();
		}
		// Get to next event time instant
		timestep = nextEvent.getStep();
	}
	cout << population << endl;
}