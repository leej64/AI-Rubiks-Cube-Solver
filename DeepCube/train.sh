python ctg/avi.py --env cube3 --states_per_update 50000000 --batch_size 10000 --nnet_name cube3 --max_itrs 1000000 --loss_thresh 0.06 --back_max 30 --num_update_procs 30
cp -r saved_models/cube3/current/* saved_models/cube3/target/
python ctg/avi.py --env cube3 --states_per_update 50000000 --batch_size 10000 --nnet_name cube3 --max_itrs 1200000 --loss_thresh 0.06 --back_max 30 --num_update_procs 30

python search/astar.py --states data/cube3/data_0.pkl --model saved_models/cube3/current/ --env cube3 --weight 0.6 --batch_size 10000 --results_dir results/cube3/ --language cpp --nnet_batch_size 10000

python python scripts/compare_solutions.py --soln1 data/cube3/data_0.pkl --soln2 results/cube3/results.pkl