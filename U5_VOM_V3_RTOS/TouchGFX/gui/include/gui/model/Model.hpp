#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void updateTemp(unsigned int val);
    void updateVolt(unsigned int val);

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
