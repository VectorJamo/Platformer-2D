#include "src/layers/Layer.h"
#include "../objects/Coin.h"
#include "../objects/Objects.h"
#include <iostream>
#include <vector>

class ObjectLayer : public Layer
{
private:
	static constexpr int m_NumCoins = 8;
	std::vector<Coin*> m_Coins;

public:
	ObjectLayer(const std::string& layerName, SDL_Renderer* renderer);
	~ObjectLayer();
	
	void Update() override;
	void Render() override;

	inline std::vector<Coin*>& GetCoins() { return m_Coins; }
};