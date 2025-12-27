#include <iostream>
#include <string>
#include <unordered_map>

class Layer
{
protected:
	std::string m_LayerName;

public:
	static std::unordered_map<std::string, Layer*> CurrentLayers;

public:
	Layer(const std::string& layerName);
	~Layer();

	virtual void Update() = 0;
	virtual void Render() = 0;
};