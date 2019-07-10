#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <functional>
#include <map>

template <typename... Args>
class Signal {

    public:

        Signal() : currentId(0) {}

        Signal(Signal const& other) : currentId(0) {}

        template <typename T>
        int connect(std::function<void(Args...)> const& slot) const {
            this->slots_.insert(std::make_pair(++this->currentId, slot));
            return this->currentId;
        }

    private:
        mutable std::map<int, std::function<void(Args...)>> slots;
        mutable int currentId;
};

#endif